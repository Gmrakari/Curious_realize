#include "iostream"
using namespace std;

//date:2018-10-27 17:05
//Author : null
//多继承的语法(其它语言中没有多继承的概念)
//

//多继承的概念：一个类有多个直接基类的继承关系称为多继承

//语法

/*class 派生类名:访问控制 基类名1,访问控制 基类名2,...,访问控制 基类名n 
{
	数据成员和成员函数声明
};*/

//多继承的派生类构造和访问
/*
1、多个基类的派生类构造函数可以用初始式调用基类构造函数初始化数据成员
2、执行顺序语单继承构造函数情况类似。多个直接基类构造函数执行顺序取决于定义派生类时指定的各个继承基类的顺序
3、一个派生类对象拥有多个直接或间接基类的成员。不同名成员访问不会出现二义性，如果不同的基类有同名成员，派生类对象访问时应该加以识别。*/

class Base1
{
public:
	Base1(int b1)
	{
		this->b1 = b1;
	}
	void printB1()
	{
		cout<<"b1:"<<b1<<endl;
	}
protected:
private:
	int b1;
};

class Base2
{
public:
	Base2(int b2)
	{
		this->b2 = b2;
	}
	void printB2()
	{
		cout<<"b2:"<<b2<<endl;
	}
protected:
private:
	int b2;
};

class B:public Base1,pulic Base2
{
public:
	B(int a,int b,int c):Base1(b1),Base2(b2)
	{
		this->c = c;
	}
	void printC()
	{
		cout<<"c:"<<c<<endl;
	}
protected:
private:
	int c;
};

void main()
{
	B b1(1,2,3);
	b1.pirntC();
	b1.printB1();
	b1.printB2();

	cout<<"hellc"<<endl;

	system("pause");
}