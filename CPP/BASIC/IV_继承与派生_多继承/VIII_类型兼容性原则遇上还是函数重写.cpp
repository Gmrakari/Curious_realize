#include "iostream"
using namespace std;

//date:2018-10-28 11:32
//Author : null
//类型兼容性原则遇上还是函数重写
//

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
		cout<<"a"<<a<<endl;
	}
protected:
private:
	int a;
};

class Child :public Parent
{
public:
	Child(int b)
	{
		this->b = b;
		cout<<"Child b"<<b<<endl;
	}
	virtual void print()//子类的和父类的函数名字一样 
	{
		cout<<"Parent打印 a:"<<a<endl;
	}
protected:
private:
	int a;
};


class Child : public Parent{
public:
	Child(int b):Parent(10)
	{
		this->b = b;
		cout<<"Child b"<<b<<endl;
	}
	virtual void print()//父类写了 virtual ，子类可写 可不写
	{
		cout<<"Child 打印 b:"<<b<<endl;
	}
private:
	int b;
};

void howToPrint(Parent *base)
{
	base->print();
}

void howToPrint2(Parent &base)
{
	base->print();
}

void main()
{
	Parent *base = NULL;
	Parent p1(20);
	Child c1(30);

	base = &p1;
	base->print();//执行父类的打印函数

	base = &c1;
	base->print();//执行谁的函数?//面向对象新需求

	{
		Parent &base2 = p1;
		base2.print();

		Parent &base3 = c1;// base3是c1 的别名
		base2.print();
			
	}

	//函数调用
	howToPrint(&p1);
	howToPrint(&c1);

	howToPrint2(p1);
	howToPrint2(c1);

	cout<<"hellc"<<endl;
	system("pause");
}