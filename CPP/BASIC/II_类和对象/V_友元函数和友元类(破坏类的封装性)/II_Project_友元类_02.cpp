#include "iostream"
using namespace std;

//date:2018-09-08 11:01
//Author : null
//友元函数和友元类
//Project_02友元类

class A
{
public:
	friend class B;//B 类是 A 的好朋友 ，在B中可以访问A类的私有成员 私有函数
	//声明的位置 和public private 无关
	friend void modifyA(A *pA,int _a);//函数modifyA 是类A的 好朋友
	A(int a = 0,int b = 0) 
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{
		return this->a;
	}
private:
	int a;
	int b;
};

//为什么设计友元类函数
//1.java ---->1.class(字节码) ==》反射机制 分析 1.class 找到类对象，直接修改类的私有属性
//反射机制 成为一种标准 .太阳公司把它做成标准 ,jdk  的 api函数中有体现
//AOP
//2.1 cpp===> 预编译 、 编译 、 连接 、 生成 gcc -E //gcc -s -
//gcc -o 1.exe 1.c
//编译往回找  很难
//3 开了一个后门 friend 

void modifyA(A *pA,int _a) 
{
	pA->a = _a;
	/*pA->a = 100; ---//无法访问A的private 属性*/
}

class B
{
public:
	void Set(int a)
	{
		Aobject.a = a;
	}
	void printB()
	{
		cout<<Aobject.a<<endl;
	}
private:
	A Aobject;

};

void main()
{
	B b1;
	b1.Set(300);
	b1.printB();
	system("pause");
}

void main01()
{
	A a1(1,2);
	cout<<a1.getA()<<endl;
	
	modifyA(&a1,300);
	cout<<a1.getA()<<endl;

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
