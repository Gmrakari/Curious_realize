#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-08 11 : 05 
//Author : null
//Project:异常的基本语法

//基本语法
//发生异常之后，是跨函数
//接受的异常 可以不处理
//catch 异常时，按照类型进行catch 
//异常 捕捉 严格 按照类型匹配

voic main()
{
	try{
		throw 'Z';
	}
	catch(int e)
	{
		cout<<"捕获Int 类型异常"<<endl;
	}
	catch(...)
	{
		cout<<"未知 类型异常"<endl;
	}
}


void divide(int x,int y)
{
	if(y == 0)
	{
		throw x;// 抛出 int类型 异常
	}

	cout<< "divide result: "<<x/y<<endl;
}

void myDivide(int x,y)
{
	try
	{
		divide(x,y);
	}
	catch(...)
	{
		cout<<"我接受了divide的异常  但是我没有处理  我向上抛出"<<endl;
		throw;
	}
	
}

void main()
{
	try
	{
		divide(10,2);
		divide(100,0);
	}
	catch(int e)
	{
		cout<<e<<"被零除"<<endl;
	}
	catch( ... )//没有捕捉到 
	{
		cout<<"其它未知类型异常"<<endl;
	}
	catch(CMemoryException *e)
	{

	}
	catch(CFileException* e)
	{

	}
	catch(CException* e)
	{

	}
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}