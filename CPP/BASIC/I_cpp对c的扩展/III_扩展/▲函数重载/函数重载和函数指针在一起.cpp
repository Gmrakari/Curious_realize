
//函数重载和函数指针在一起
//Date:2018-08-30 13：44
//Author:null
#include "iostream"
using namespace std;

void myfunc(int a);
{
	printf("a:%d\n", );
}

void myfunc(char *p)
{
	printf("%s\n",p );
}

void myfunc(char *p1,char *p2)
{
	printf("p1:%d p2:%d\n", p1,p2);
}

//函数指针 基础的语法
//声明一个函数类型

//void myfunc(int a,int b)
typedef void (myTypeFunc)(int a,int b);//int定义一个函数指针 这个指针指向函数的入口地址

//声明一个函数指针类型
typedef void(*myPTypeFunc)(int a,int b);//声明一个指针的数据类型
//myTypeFunc fp = NULL;//通过 函数指针类型 定义了 一个函数指针

//定义一个函数指针 变量
void (*myVarPFunc)(int a,int b);


void main()
{
	myTypeFunc *myfuncp = NULL;//
	myTypeFunc fp;//定义一个函数指针 变量

	fp = myfunc;

	fp(1,2);

	

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
