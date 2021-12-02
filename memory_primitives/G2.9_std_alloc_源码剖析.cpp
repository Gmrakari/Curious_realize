

/*
 * Date:2021-12-02 14:42
 * filename:G2.9_std_alloc_源码剖析.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define __THROW_BAD_ALLOC  cerr << "out of memory" << endl; exit(1)

//----------------------------------------------
// 第1級配置器。
//----------------------------------------------
template <int inst>
class __malloc_alloc_template {
private:
  static void* oom_malloc(size_t);
  static void* oom_realloc(void *, size_t);
  static void (*__malloc_alloc_oom_handler)();

public:
  static void* allocate(size_t n)
  {
    void *result = malloc(n);   //直接使用 malloc()
    if (0 == result) result = oom_malloc(n);
    return result;
  }
  static void deallocate(void *p, size_t /* n */)
  {
    free(p);                    //直接使用 free()
  }
  static void* reallocate(void *p, size_t /* old_sz */, size_t new_sz)
  {
    void * result = realloc(p, new_sz); //直接使用 realloc()
    if (0 == result) result = oom_realloc(p, new_sz);
    return result;
  }
  static void (*set_malloc_handler(void (*f)()))()
  { //類似 C++ 的 set_new_handler().
    void (*old)() = __malloc_alloc_oom_handler;
    __malloc_alloc_oom_handler = f;
    return(old);
  }
};
//----------------------------------------------
template <int inst>
void (*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

template <int inst>
void* __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
  void (*my_malloc_handler)();
  void* result;

  for (;;) {    //不斷嘗試釋放、配置、再釋放、再配置…
    my_malloc_handler = __malloc_alloc_oom_handler;
    if (0 == my_malloc_handler) { __THROW_BAD_ALLOC; }
    (*my_malloc_handler)();    //呼叫處理常式，企圖釋放記憶體
    result = malloc(n);        //再次嘗試配置記憶體
    if (result) return(result);
  }
}

template <int inst>
void * __malloc_alloc_template<inst>::oom_realloc(void *p, size_t n)
{
  void (*my_malloc_handler)();
  void* result;

  for (;;) {    //不斷嘗試釋放、配置、再釋放、再配置…
    my_malloc_handler = __malloc_alloc_oom_handler;
    if (0 == my_malloc_handler) { __THROW_BAD_ALLOC; }
    (*my_malloc_handler)();    //呼叫處理常式，企圖釋放記憶體。
    result = realloc(p, n);    //再次嘗試配置記憶體。
    if (result) return(result);
  }
}
//----------------------------------------------

typedef __malloc_alloc_template<0>  malloc_alloc;

template<class T, class Alloc>
class simple_alloc {
public:
  static T* allocate(size_t n)
    { return 0 == n? 0 : (T*)Alloc::allocate(n*sizeof(T)); }
  static T* allocate(void)
    { return (T*)Alloc::allocate(sizeof(T)); }
  static void deallocate(T* p, size_t n)
    { if (0 != n) Alloc::deallocate(p, n*sizeof(T)); }
  static void deallocate(T *p)
    { Alloc::deallocate(p, sizeof(T)); }
};

//第二级分配器
enum { __ALIGN = 8 };			//小区块的上调边界
enum { __MAX_BYTES = 128 };//小区块上限
enum { __NFREELISTS = __MAX_BYTES / __ALIGN };//free-list 个数


template <bool threads, int inst>
class __default_alloc_template {
private:
	//调整，如果bytes = 13,调用ROUND_UP 调整为16 8的倍数
	static size_t ROUND_UP(size_t bytes) {
		return (((bytes) + __ALIGN - 1) & (__ALIGN - 1));
	}

private:
	union obj {
		union obj* free_list_link;//struct obj* next;
	};
	
private:
	static obj* volatile free_list[__NFREELISTS];
	static size_t FREELIST_INDEX(size_t bytes) {
		return (((bytes) + __ALIGN - 1) / __ALIGN - 1);
	}

	//returns an object of size n and optionally adds to size n free list
	static void *refill(size_t n);

	//Allocates a chunk for nobjs of size "size". nobjs may be reduced
	//if it is inconvenient to allocate the requested number
	static char* chunk_alloc(size_t size,int &nobjs);

	//Chunk allocation state.
	static char* start_free;	//指向'pool'的头
	static char* end_free;    //指向'pool'的尾
	static size_t heap_size;  //分配累计量

public:
	static void* allocate(size_t n) { //n must be > 0
		obj* volatile *my_free_list; //obj** 
		obj* result;

		if (n > (size_t)__MAX_BYTES) { //改用第一级
			return (malloc_alloc::allocate(n));
		}
	
		my_free_list = free_list + FREELIST_INDEX(n);
		result = *my_free_list;

		if (result == 0) {//list为空
			void* r = refill(ROUND_UP(n));
			return r;
		} 

		*my_free_list = result->free_list_link;
		reutrn (result);
	}

	static void deallocate(void* p, size_t n) { //p不为0
		obj* q = (obj*)p;
		obj* volatile *my_free_list;

		if (n > (size_t)__MAX_BYTES) {
			malloc_alloc::deallocate(p, n); //改用第一级
			return ;
		}

		my_free_list = free_list + FREELIST_INDEX(n);
		q->free_list_link = *my_free_list;
		*my_free_list = q;
	}

	static void* reallocate(void* p, size_t old_sz, size_t new_sz);
};
