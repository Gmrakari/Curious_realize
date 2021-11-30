

/*
 * Date:2021-11-30 09:08
 * filename:jjhou_内存管理实例.cpp
 *
 */

#include <iostream>
#include <complex>
#include <memory>
using namespace std;

namespace jj01 {
	void test_primitives() {
		cout << "\ntest_primitives()\n";

		void* p1 = malloc(512);
		free(p1);

		complex<int>* p2 = new complex<int>;
		delete p2;

		void* p3 = ::operator new(512);
		::operator delete(p3);
	}
}

#include <iostream>
#include <string>

namespace jj02 {
	class A {
		public:
			int id;
			A() : id(0) {
				cout << "default ctor. this=" << this << " id=" << id << endl;
			}

			A(int i) : id(i) {
				cout << "ctor. this=" << this << " id=" << id << endl;
			}

			~A() {
				cout << "dtor. this=" << this << " id=" << id << endl;
			}
	};

	void test_call_ctor_directly() {
		cout << "\ntest_call_ctor_directly()\n";

		string* pstr = new string;
		cout << "str=" << *pstr << endl;

		cout << "str=" << *pstr << endl;

		A* pA = new A(1);
		cout << "pA->id:" << pA->id << endl;

		cout << "pA->id:" << pA->id << endl;

		delete pA;

		void* p = ::operator new(sizeof(A));
		cout << "p=" << p << endl;

		pA = static_cast<A*>(p);

		cout << "pA->id:" << pA->id << endl;

		pA->~A();
		::operator delete(pA);
	}
}

#include <iostream>
#include <new>

namespace jj03 {
	using jj02::A;

	void test_array_new_and_placement_new() {
		cout << "\ntest_placement_new()\n";

		size_t size = 3;
		{
			//case 1
			//array new + placement new. -->err
			A* buf = (A*)(new char[sizeof(A) * size]);
			A* tmp = buf;

			cout << "buf=" << buf << " tmp=" << tmp << endl;

			for (int i = 0;i < (int)size;++i) 
				new (tmp++) A(i);//3次ctor

			cout << "buf=" << buf << " tmp=" << tmp << endl;
			delete buf;

			cout << endl;
		}
		{
			cout << "case2:\n";

			A* buf = new A[size];
			A* tmp = buf;

			cout << "buf=" << buf << " tmp=" << tmp << endl;

			for (int i = 0; i < (int)size; ++i) 
				new (tmp++) A(i);

			cout << "buf=" << buf << " tmp=" << tmp << endl;

			delete[] buf;
		}
	}
}

#include <cstddef>
#include <iostream>

namespace jj04 {
	class Screen {
	public:
		Screen(int x) : i(x) {};
		int get() {
			return i;
		}

		void* operator new(size_t);
		void operator delete(void*, size_t);
		//void operator delete(void*);
	private:
		Screen* next;
		static Screen* freeStore;
		static const int screenChunk;
	private:
		int i;
	};

	Screen* Screen::freeStore = 0;
	const int Screen::screenChunk = 24;

	void* Screen::operator new(size_t size) {
		Screen *p;
		if (!freeStore) {
			//linked list是空的，获取一大块memory
			//呼叫global operator new
			size_t chunk = screenChunk * size;
			freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);
			//将分配得来的一大块memory当作linked list般小块小块串接起来
			for (; p != &freeStore[screenChunk - 1]; ++p)
				p->next = p + 1;
			p->next = 0;
		}
		p = freeStore;
		freeStore = freeStore->next;
		return p;
	}

	void Screen::operator delete(void *p, size_t) {
		//将delete object收回插入free list前端
		(static_cast<Screen*>(p))->next = freeStore;
		freeStore = static_cast<Screen*>(p);
	}

	void test_pre_class_allocator_1() {
		cout << "\ntest_pre_class_allocator_1()\n";
		cout << sizeof(Screen) << endl;

		size_t const N = 100;
		Screen* p[N];

		for (int i = 0;i < (int)N; ++i) 
			p[i] = new Screen(i);

		//输出前10个pointers,用以比较其间隔
		for (int i = 0;i < 10; ++i)
			cout << p[i] << endl;

		for (int i = 0;i < (int)N; ++i)
			delete p[i];
	}
}


int main(int argc, char* argv[]) {
	cout << __cplusplus << endl;

	//jj01::test_primitives();
	//jj02::test_call_ctor_directly();
	//jj03::test_array_new_and_placement_new();
	jj04::test_pre_class_allocator_1();
}
