#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-28 
//Author : null
//重载重写重定义

//重写发生在2个类之间

//重载必须在一个类之间

//重写分为2个类
//1、虚函数重写 将发生多态
//2、 非虚函数重写 （重定义）

class Parent
{
	//这个三个函数都是重载关系
public:
	virtual void func()
	{
		cout<<"func() do ..."<<endl; 
	}
	virtual void func(int i)
	{
		cout<<"func() do ..."<<i<<endl;
	}
	virtual void func(int i,int j)
	{
		cout<<"func(int i,int j) do ..,."<<endl;
	}
protected:
private:
};

class Child : public Parent
{
public:
	virtual void func(int i)
	{
		cout<<"func() do ..."<<i<<endl;
	}
	virtual void func(int i,int j,int k)
	{
		cout<<"func(int i,int j) do ..,."<<endl;
	}
protected:
private:
};


void main()
{
	//error :"Child::func ":没有重载函数接受0个参数
	Child c1;
	//子类无法重载父类的函数，父类同名函数将被名称覆盖
	
	//重载在同一类之间...
	//c1.func();
	c1.Parent::func();

	//1、cpp编译器 看到func名字，因在子类func名字中已经存在了，所以cpp编译器不会去找父类的4个参数的func函数
	//2、cpp编译器只会在子类中，查找func函数，找到了两个func，一个是2个参数的，一个是3个参数的
	//3、cpp编译器开始报错 
	//4、若想调用父类的func，只能加上父类的域名:: 这样去调用
	c1.func(1,2,3,4);

	//c1.func();
	//func函数的名字，在子类中发生了名称覆盖；子类的函数的名字，占用了父亲的函数的名字的位置
	//因为子类中已经有了func名字的重载形式
	//编译器开始在子类中找func函数。。。。。但是没有0个参数的func函数


	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	