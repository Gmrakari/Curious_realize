#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-29 16:11
//Author : null
//纯虚函数抽象类语法基础

	//面酱抽象类编程(面向一套预先定义好的接口编程)
	//解耦合...模块的划分

//抽象类(含有纯虚函数的类叫抽象类)
class Figure
{
public:
	//阅读一个统一的界面（接口），让子类使用，让子类必须去实现
	virtual void getArea() = 0;//纯虚函数 
protected:
private:
};

class Circle :public Figure
{
public:
	Circle(int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout<<"The area of circle:"<<3.14*a*a<<endl;
	}
protected:
private:
	int a;
	int b; 
};

class Triangle :public Figure
{
public:
	Triangle(int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout<<"The area of Triangle:"<<a*b/2<<endl;
	}
protected:
private:
	int a;
	int b; 
};

class Square :public Figure
{
public:
	Square(int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout<<"The area of Square:"<<a*b<<endl;
	}
protected:
private:
	int a;
	int b; 
};

void objplay(Figure *base)
{
	base->getArea();//会发生多态
}
void main()
{
	//Figer f;//抽象类不能被实例化
	
	Figer *base = NULL;//抽象类不能被实例化

	Circle c1(10,20);
	Triangle t1(20,30);
	Square s1(50,60);

	//面向抽象类编程(面向一套预先定义好的接口编程)
	objplay(&c1);
	objplay(&t1);
	objplay(&s1);

	//c1.getArea();


	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	