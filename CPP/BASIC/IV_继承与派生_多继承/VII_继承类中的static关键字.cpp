#include "iostream"
using namespace std;

//date:2018-10-27 16:40
//Author : null
//派生类中的static关键字

//单例
class A
{
	A()//无法访问A类的构造函数，不写访问控制，A类的构造函数是私有的函数,要注意别的类的继承
	{
		cout<<"A的构造函数"<<endl;
	}
public:
	static int a;
	int b;
	int c;
protected:
private:
public:
	void get()
	{
		cout<<"b "<<b<<endl;
	}
};

//int A::a = 100;//这表明不是简单的变量赋值，这表明告诉cpp编译器，给变量分配内存，我在继承类中 用到了 a 不然会报错

class B :private A
{
public:
	int b;
	int c;
public:
	void get_child()
	{
		cout<<"b"<<b<<endl;
		cout<<"a"<<a<<endl;
	}
	void print()
	{
		cout<<"BBBB "<<endl;
	}
}

//2
void main()
{
	A a1;
	a1.print();

	B b1;
	system("pause");
}

//3 A类中添加构造函数
void main()
{
	A a1;

}



//1 static关键字 遵守 派生类的访问控制规则
//
//2  不是简单的变量赋值 更重要的是 要告诉C++编译器 你要给我分配内存 ,我再继承类中 用到了a 不然会报错..

//3 A类中添加构造函数 
	//A类的构造函数中   A的构造函数是私有的构造函数 ... 
	//被别的类继承要小心....
	//单例场景 .... UML

void main()
{
	A a1;
	//a1.print();

	 //B b1;
	// b1.get_child();
	system("pause");
}

void main01()
{
	// B  b1;
	 //b1.a = 200;
	system("pause");
}
