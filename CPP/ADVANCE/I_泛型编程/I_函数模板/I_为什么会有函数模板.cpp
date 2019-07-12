#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-11-20 16 : 01 
//Author : null
//为什么会有函数模板和基本语法

//函数的业务逻辑一样
//但是函数函数类型 不一样
void myswap(int &a,int &b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void myswap02(char &a,char &b)
{
	char c = 0;
	c = a;
	a = b;
	b = c;
}

//让 类型参数化 ===, 方便程序员进行编码
//泛型编程
//template 告诉cpp编译器 我要开始泛型编程了，看到T，不要随便报错
template<typename T>
void myswap(T &a,T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
	cout<<"调用myswap"<<;
}

void main01()
{
	{
		int x = 10;
		int y = 20;

		myswap(x,y);
		printf("x:%d,y:%d\n",x,y);	
	}
	
	{
		char a = 'a';
		char b = 'b';
		myswap02(a,b);


		myswap(a,b);
		printf("a:%c,b:%c\n",a,b);	
	}

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}

//函数模板的调用
//显示类型 调用
//自动类型 推导

void main()
{
	{
		int x = 10;
		int y = 20;

		myswap<int>(x,y);//1、函数模板 显示类型 调用
		myswap(x,y);//2、函数模板 自动类型 推导
		printf("x:%d,y:%d\n",x,y);	
	}

	{
		char a = 'a';
		char b = 'b';

		myswap<char>(a,b);//函数模板 显示类型 调用
		printf("a:%c,b:%c\n",a,b);	//2、函数模板 自动类型 推导
	}

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}