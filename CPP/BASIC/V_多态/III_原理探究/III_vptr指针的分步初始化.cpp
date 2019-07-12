#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-29 13:51
//Author : null
//vptr指针的分步初始化

//构造函数中调用虚函数
class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		print();
	}
	virtual void pirnt()
	{
		cout<<"我是父类"<<end;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int a = 0,int b = 0):Parent(a)
	{
		this->b = b;
		print();
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
}

void main()
{
	Child c1;//定义一个子类对象，在这个过程中，在父类构造函数中调用虚函数print 能发生多态吗?
	//c1.print();

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}