#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-29 13:43
//Author : null
//证明vptr指针的存在


class Parent1
{
public:
	Parent(int a = 0)
	{
		this->a = a;

	}
	void pirnt()
	{
		cout<<"我是父类"<<end;
	}
private:
	int a;
};

class Parent2
{
public:
	Parent2(int a = 0)
	{
		this->a = a;
	}
	virtual void pirnt()
	{
		cout<<"我是子类"<<end;
	}
private:
	int a;
};


void main()
{
	//Parent p1();//3动手脚 	提前布局
				//用类定义对象的时候 cpp编译器会在对象中添加一个vptr指针

	printf("sizeof(Parent1):%d sizeof(Parent2):%d",sizeof(Parent1),sizeof(Parent2));
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}






