#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-29 16:45
//Author : null
//抽象类在多继承中的应用

class Interface1
{
public:
	virtual int add(int a,int b) = 0;
	virtual void print() = 0;

};

class Interface2
{
public:
	virtual int add(int a,int b) = 0;
	virtual void print() = 0;
};

class Parent
{
public:
	int getA()
	{
		a = 0;
		return a;
	}
protected:
private:
};

class Child:public Parent,public Interface1,public Interface2
{
public:
	virtual int add(int a,int b)
	{
		cout<<"Child:add()已经执行"<<endl;
		return a+b;
	}
	virtual void print() 
	{
		cout<<"Child:print()已经执行"<<endl;
	}
	virtual int mult(int a,int b)
	{
		cout<<"Child:mult()已经执行"<<endl;
		return a*b;
	}
}

void main()
{
	Child c1;
	c1.print();

	Interface1 *it1 = &c1;
	it1->add(1,2);

	Interface2 *it2 = &c1;
	it2->mult(4,6);

	
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	