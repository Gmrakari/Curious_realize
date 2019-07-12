#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-11-17 11 : 20
//Author : null
//c多态课堂操练_函数指针基本语法知识梳理

//函数指针基本语法知识梳理
//1、如何定义一个函数类型
//2、如何定义一个函数指针类型
//3、如何定义一个 函数指针(指向一个函数的入口地址)

int add(int a,int b)
{
	printf("func add..\n");
	return a+b;
}

void main()
{
	add(1,2);//直接调用 函数名就是函数的入口地址 

	//定义一个函数类型
	{
		typedef int (MyFunType)(int a,int b);//定义了一个类型
		MyFunType *myPointerFunc = NULL;//定义了一个指针，指向某一种类的函数

		myPointerFunc = &add;

		myPointerFun(3,4);//间接调用 
	}

	//2、如何定义一个函数指针类型
	{
		typedef int (*MyPointerFuncType)(int a,int b);//相当于 int *a = NULL;
		MyPointerFuncType myPointerFunc;//定义一个指针
		myPointerFunc = add;
		myPointerFunc(5,6);
	}

	//3、如何定义一个 函数指针(指向一个函数的入口地址)
	{
		int (*MyPointerFunc)(int a,int b);//定义了一个变量
		MyPointerFunc = add;
		MyPointerFunc(7,8);
	}


	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	