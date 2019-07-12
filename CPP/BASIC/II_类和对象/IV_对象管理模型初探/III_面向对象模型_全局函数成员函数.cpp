#include "iostream"
using namespace std;

//date:2018-09-07 19：00
//Author : null
//Project:全局函数PK成员函数
//面向对象模型_全局函数成员函数

class Test
{
public:
	int a;
	int b;
public:
	~Test()
	{
		cout<<"a"<<a<<"b:"<<b<<endl;
		cout<<"析构函数自动被调用"<<endl;
	}
public:
	void printT()
	{
		cout<<"a"<<a<<"b:"<<b<<endl;
	}
public:
	//t3 = t1.TestAdd(t2);
	Test TestAdd(Test &t2)
	{
		Test tmp(this->a + t2.a,this->b + t2.b);
		return tmp;
	}	
public:
	Test(int a = 0,int b = 0)
	{
		this->a = a;
		this->b = b;
	}
protected:
private:
};

void printT(Test *pT)//把成员函数 转成 全局函数 多了一个参数
{
	cout<<"a"<<a<<"b:"<<b<<endl;
}

//全局函数的方法
//全局函数 转成 成员函数 少一个参数
void TestAdd(Test &t1,Test &t2)
{
	Test tmp;
	return tmp;
}


void main()
{
	Test t1(1,2);
	Test t2(3,4);	

	Test t3;
	//全局函数的方法
	t3 = TestAdd(t1,t2);

	//成员函数方法
	{	//先把测试案例写出来
		Test t4 = t1.TestAdd(t2);//匿名对象直接转化为t4
		Test t5;
		t5 = t1.TestAdd(t2);//匿名对象 复制 给t5
		t5.printT();
	}

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}

//t1.TestAdd2(t2);
//返回一个引用 相当于返回自身
//返回t1这个元素 this 就是&t1
Test& TestAdd2(Test &t2)
{
	this->a = this->a + t2.a;
	this->b = this->b + t2.b;

	return *this;//把this指针 回到元素 原始状态 
}