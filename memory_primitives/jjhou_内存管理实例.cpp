

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

#include <cstddef>
#include <iostream>

namespace jj05 {
	//per-class allocator
	class Airplane { //支援customized memory management
	private:
		struct AirplaneRep {
			unsigned long miles;
			char type;
		};
	private:
		union {
			AirplaneRep rep;//used object
			Airplane* next;//free list
		};

	public:
		unsigned long getMiles() {
			return rep.miles;
		}
		char getType() {
			return rep.type;
		}
		void set(unsigned long m, char t) {
			rep.miles = m;
			rep.type = t;
		}

	public:
		static void* operator new(size_t size);
		static void operator delete(void* deadObject, size_t size);

	private:
		static const int BLOCK_SIZE;
		static Airplane* headOfFreeList;
	};

	Airplane* Airplane::headOfFreeList;
	const int Airplane::BLOCK_SIZE = 512;

	void* Airplane::operator new(size_t size) {
		//如果大小错误，转交给::operator new()
		if (size != sizeof(Airplane))
			return ::operator new(size);

		Airplane* p = headOfFreeList;

		//如果p有效，就把list头部移往下一个元素
		if (p) 
			headOfFreeList = p->next;
		else {
			//free list 已空，配置一块够大记忆体
			//令足够容纳BLOCK_SIZE个airplanes
			Airplane* newBlock = static_cast<Airplane*>(::operator new(BLOCK_SIZE * sizeof(Airplane)));
			//组成一个新的free list:将小区块串在一起，
			//但跳过#0元素，因为要将它传回给呼叫者
			for (int i = 1;i < BLOCK_SIZE - 1; ++i) 
				newBlock[i].next = &newBlock[i + 1];
			newBlock[BLOCK_SIZE - 1].next  = 0;//以NULL结束

			//将p设至头部，将headOfFreeList设至下一个可被运用的小区块
			p = newBlock;
			headOfFreeList = &newBlock[1];
		}
		return p;
	}

	//operator delete 截获一块记忆体
	//如果它的大小正确，就把它加到free list的前端
	void Airplane::operator delete(void* deadObject, size_t size) {
		if (deadObject == 0)
			return ;

		if (size != sizeof(Airplane)) {
			::operator delete(deadObject);
			return ;
		}

		Airplane *carcass = static_cast<Airplane*>(deadObject);
		carcass->next = headOfFreeList;
		headOfFreeList = carcass;
	}

	void test_per_class_allocator_2() {
		cout << "\ntest_per_class_allocator_2()..\n";
		cout << "sizeof(Airplane):" << sizeof(Airplane) << endl;
		size_t const N = 100;

		Airplane* p[N];

		for (int i = 0;i < (int)N;++i)
			p[i] = new Airplane;

		//随机测试object 是否正常
		p[1]->set(1000, 'A');
		p[2]->set(2000, 'B');
		p[3]->set(50000, 'C');

		cout << p[1] << ' ' << p[1]->getType() << ' ' << p[1]->getMiles() << endl;
		cout << p[3] << ' ' << p[3]->getType() << ' ' << p[3]->getMiles() << endl;
		cout << p[5] << ' ' << p[5]->getType() << ' ' << p[5]->getMiles() << endl;
		cout << p[9] << ' ' << p[9]->getType() << ' ' << p[9]->getMiles() << endl;

		//输出前10个pointers, 用以比较其间隔
		for (int i = 0;i < 10; ++i)
			cout << p[i] << endl;

		for (int i = 0;i < (int)N; ++i)
			delete p[i];
	}
}

#include <cstddef>
#include <iostream>
#include <string>
namespace jj06 {
	class Foo {
	public:
		int _id;
		long _data;
		string _str;

	public:
		static void* operator new(size_t size);
		static void operator delete(void* deadObject, size_t size);
		static void* operator new[](size_t size);
		static void operator delete[](void* deadObject, size_t size);

		Foo() : _id(0) {
			cout << "default ctor. this=" << this << " id=" << _id << endl;
		}

		Foo(int i) : _id(i) {
			cout << "ctor. this=" << this << " id=" << _id << endl;
		}

		~Foo() {
			cout << "dtor. this=" << this << " id=" << _id << endl;
		}

	};
	void* Foo::operator new(size_t size) {
		Foo* p = (Foo*)malloc(size);
		cout << "Foo::operator new(), size=" << size << "\t return: " << p << endl;
		return p;
	}

	void Foo::operator delete(void* pdead, size_t size) {
		cout << "Foo::operator delete(), pdead = " << pdead << " size=" << size << endl;
		free(pdead);
	}

	void* Foo::operator new[](size_t size) {
		Foo* p = (Foo*)malloc(size);
		cout << "Foo::operator new[](), size=" << size << "\t return: " << p << endl;
		return p;
	}

	void Foo::operator delete[](void *pdead, size_t size) {
		cout << "Foo::operator delete[], pdead = " << pdead << " size=" << size << endl;
		free(pdead);
	}

	void test_overload_operator_new_and_array_new() {
		cout << "test_overload_operator_new_and_array_new\n";

		cout << "sizeof(Foo):" << sizeof(Foo) << endl;

		{
			Foo* p = new Foo(7);
			delete p;

			Foo* pArray = new Foo[5];
			delete[] pArray;
		}

		{
			cout << "testing global expression ::new and ::new[]\n";

			Foo* p = ::new Foo(7);
			::delete p;

			Foo* pArray = ::new Foo[5];
			::delete[] pArray;
		}
	}
}


int main(int argc, char* argv[]) {
	cout << __cplusplus << endl;

	//jj01::test_primitives();
	//jj02::test_call_ctor_directly();
	//jj03::test_array_new_and_placement_new();
	//jj04::test_pre_class_allocator_1();
	//jj05::test_per_class_allocator_2();
	jj06::test_overload_operator_new_and_array_new();

}
