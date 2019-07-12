#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-08 18:40 
//Author : null
//Projext:栈解旋unwinding

class Test3
{
public:
	Test3(int a = 0,int b = 0)
	{
		this->a = a;
		this->b = b;
		cout<<"构造函数"<<endl;
	}
	~Test3()
	{
		cout<<"析构函数"<<endl;
	}
private:
	int a;
	int b;
};

void myDivide()
{
	Test3 t1(1,2),t2(3,4);
	cout<<"myDivide..要发生异常"<<endl;
	throw 1;
}

void main()
{
	try
	{
		myDivide();
	}
	catch(int a)
	{
		cout<<"int 异常"<<endl;
	}
	catch(...)
	{
		cout<<"未知 异常"<<endl;
	}
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	