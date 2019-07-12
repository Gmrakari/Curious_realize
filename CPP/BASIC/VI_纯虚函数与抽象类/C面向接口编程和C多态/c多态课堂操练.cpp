#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-11-17 11 : 05 
//Author : null
//c多态课堂操练_数组类型基本语法知识梳理
//函数指针语法基础
//
//

/*int a[10];*/

//定义一个数组类型

//定义一个指针数组类型

//定义一个指向 数组类型的指针 数组类的指针

//



void main()
{
	int a[10];//a代表的是数组首元素的地址 &a代表整个数组的地址 a+1(4) &a+1(40)步长不一样

	//定义一个数组类型
	{
		typedef int (myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;
		printf("%d\n",myArray[0]);
	}

	//定义一个指针数组类型
	{
		typedef int (*PTypeArray)[10];//int *p

		PTypeArray myPArray;//sizeof(int) * 10;

		myPArray = &a;
	/*  int b = 10;
		int *p = NULL;
		p = &b;		*/
		(*myPArray)[0] = 20;

		printf("a[0]:%d\n",a[0]);
	}

	//定义一个指向 数组类型的指针 数组类的指针		
	{
		int (*MyPointer)[10];//变量  告诉c编译器 给我分配内存
		MyPointer = &a;
		(*MyPointer)[0] = 40;

		printf("a[0]:%d\n",a[0]);
	}

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	