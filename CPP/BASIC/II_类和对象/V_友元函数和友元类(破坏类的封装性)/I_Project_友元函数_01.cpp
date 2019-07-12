#include "iostream"
using namespace std;

//date:2018-09-08 11:01
//Author : null
//友元函数和友元类
//

class A
{
public:
	//声明的位置 和public private 无关
	friend void modifyA(A *pA,int _a);//函数modifyA 是类A的 好朋友
	A(int a,int b) 
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{
		return this->a;
	}
private:
	int a;
	int b;
};

void modifyA(A *pA,int _a) 
{
	pA->a = _a;
	/*pA->a = 100; ---//无法访问A的private 属性*/
}

void main()
{
	A a1(1,2);
	cout<<a1.getA()<<endl;
	
	modifyA(&a1,300);
	cout<<a1.getA()<<endl;

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}

