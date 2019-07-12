#include "iostream"
using namespace std;

//date:2018-10-22 20:00
//Author : null
//继承中的构造和析构


/*问题：如何初始化父类成员？父类与子类的构造函数有什么关系？

A：在子类对象构造时，需要调用父类构造函数对其继承得来的成员进行初始
   在子类对象析构时，需要调用父类析构函数对其继承的来的成员进行清理*/

class Parent
{
public:
	Parent(int a,int b)
	{
		this->a = a;
		this->b = b;
		cout<<"父类构造函数"<<endl;
	}
	~Parent()
	{
		cout<<"构造函数"<<endl;
	}
	void printP(int a,int b)
	{
		this->a = a;
		this->b = b;
		cout<<"我是父类"<<endl;
	}
private:
	int a;
	int b;

};

class child:public Parent
{
public:
	child(int a,int b,int c):Parent(a,b)
	{
		this->c = c;
		cout<<"子类的构造函数"<<endl;
	}
	~child()
	{
		cout<<"子类的析构函数"<<endl;
	}
	void printC()
	{
		cout<<"我是子类"<<endl;
	}
private:
	int c;

};


class child:public Parent
{
public:
	child(int a,int b,int c)
	{
		this->c = c;
	}
	void printC()
	{
		cout<<"我是子类"<<endl;
	}
};

void playObj()
{
	child c1(1,2,3);
}

void main()
{
	Parent p(1,2);

	playObj();

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}

//结论
//
//先 调用父类构造函数  在条用 子类构造函数
//
//析构的顺序 和构造相反 