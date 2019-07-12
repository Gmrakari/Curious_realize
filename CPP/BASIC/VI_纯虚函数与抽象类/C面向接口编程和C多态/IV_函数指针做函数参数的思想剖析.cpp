#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-11-17 11 : 05 
//Author : null
//函数指针做函数参数的思想剖析
//
int myadd(int a,int b)//子任务的是实现者
{
	printf("func add()do..\n");
	return a+b;
}

int myadd2(int a,int b)//子任务的是实现者
{
	printf("func add2()do..\n");
	return a+b;
}

int myadd3(int a,int b)//子任务的是实现者
{
	printf("func add3()do..\n");
	return a+b;
}

int myadd4(int a,int b)//子任务的是实现者
{
	printf("func add4()do..\n");
	return a+b;
}

//定义了一个类型
typedef int (*MyTypeFuncAdd)(int a,int b);

//函数指针 做 函数参数
int MainOp(MyTypeFuncAdd myFuncAdd)
{
	int c;
	c = myFuncAdd(5,6);//间接调用
	return c;
}

//int (*MyTypeFuncAdd) (int a,int b)
int MainOp2(int (*MyTypeFuncAdd) (int a,int b))
{
	int c;
	c = myFuncAdd(5,6);//间接调用
	return c;
}

//间接调用
//任务的调用 和 任务的编写 可以分开
void main()
{
/*	MyTypeFuncAdd myFuncAdd = NULL;
	myadd(1,2);//直接调用

	myFuncAdd = myadd;
	myFuncAdd(3,4);//间接调用

	MainOp2(myadd);
	MainOp(myadd);*/

	//再mainop框架 没有发生任何变化的情况下...
	
	MainOp(myadd2);
	MainOp(myadd3);
	MainOp(myadd4);
	
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	