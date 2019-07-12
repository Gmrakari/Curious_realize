#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-28 18:47
//Author : null
//多态原理探究

//多态成立的三个条件
//要有继承 虚函数的重写 父类指针指向子类对象

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;

	}
	virtual void pirnt()//1动手脚的地方 写virtual 关键字 会特殊处理 //虚函数表
	{
		cout<<"我是父类"<<end;
	}
	virtual void pirnt2()//1动手脚的地方 写virtual 关键字 会特殊处理 //虚函数表
	{
		cout<<"我是父类"<<end;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int a = 0,int b = 0):Parent(\a)
	{
		this->b = b;
	}
	virtual void pirnt()
	{
		cout<<"我是子类"<<end;
	}
private:
	int b;
};

void HowToPlay(Parent *base)
{
	base->print();//这里会有多态发生 //2动手脚 
	//效果：传来子类对象 执行子类的print函数 传来父类对象执行父类的print()函数
	//cpp编译器根本不需要区分是子类对象还是父类对象
	//父类对象和子类对象分别有vptr指针，==>虚函数表==>函数的入口地址
	//迟绑定(运行时的时候，cpp编译器才去判断)
}


void main()
{
	Parent p1();//3动手脚 	提前布局
				//用类定义对象的时候 cpp编译器会在对象中添加一个vptr指针
	Child c1;//子类里面也有一个vptr指针

	HowToPlay(&p1);
	HowToPlay(&c1);

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}






