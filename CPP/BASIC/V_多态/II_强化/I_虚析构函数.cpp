#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-28 16:42
//Author : null
//虚析构函数
//

//虚析构函数
class A
{
public:
	A()
	{
		p = new char[20];
		strcpy(p,"obja");
		cout<<"A()"<<endl;
	}
	virtual ~A() //添加一个virtual 关键字， 打印出所有子类的析构函数 (面试题)
	{
		delete [] p;
		cout<<"~A()"<<endl;
	}
protected:
private:
	char *p;
};

class B:public A
{
public:
	B()
	{
		p = new char[20];
		strcpy(p,"objb");
		cout<<"B()"<<endl;
	}
	virtual ~B()
	{
		delete [] p;
		cout<<"~B()"<<endl;
	}
protected:
private:
	char *p;
};

class C:public B
{
public:
	C()
	{
		p = new char[20];
		strcpy(p,"objc");
		cout<<"C()"<<endl;
	}
	virtual ~C()
	{
		delete [] p;
		cout<<"~C()"<<endl;
	}
protected:
private:
	char *p;
};
//把下面的几句话 完完整整说出来。
//只执行了 父类的析构函数 
//向通过父类指针 把 所有的子类对象的析构函数 都执行一遍
//向通过父类指针 释放所有的子类资源
void howtodelete(A *base)
{	
	delete base;// 这句话 不会表现多态 这种属性
}

void main()
{
	C *myC = new C;//new delte 匹配
	howtodelete(myC);

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	