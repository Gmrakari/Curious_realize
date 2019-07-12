


//C 语言 + 面向对象方法论 ==>Objective C(IOS)/C++
//namespace


#include "iostram"
suing namespace std;


//文件中iostram 没有引入标准的std 需要我们手写
void main01()
{

	cout<<"namespace test"<<endl;
	// std::cout<<"namespace test"<<std::endl; 如果没有namespace，需要引入std


	system("pause");
}


//定义命名空间

namespace namespaceA
{
	int a = 0;
}

namespace namespaceB
{
	int a = 20;
	namespace namespaceC
	{
		struct Teacher
		{
			char name[32];
			int age;
		};
	}
}

void main()
{
	using namepace namespaceA;
	using namepace namespaceB;

	// cout<<a<<endl;
	cout<<namespaceA::a<<endl;

	namespaceB::namespaceC::Teacher t1;
	t1.age = 33;

	using namespaceB::namespaceC::Teacher;
	Teacher t2;
	t2.name  = "Rakari";
	system("pause");
}

