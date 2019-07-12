#include "iostream"
using namespace std;

//date:2018-10-27 16:30
//Author : null
//继承中的同名成员变量和同名成员函数


class A
{
public:
	int b;
	int c;
protected:
private:
public:
	void get()
	{
		cout<<"b "<<b<<endl;
	}
};

class B :public A
{
	public:
		int b;
		int c;
public:
	void get_child()
	{
		cout<<"b"<<b<<endl;
	}
	void print()
	{
		cout<<"AAAA "<<endl;
	}
}

void main()//02  
{
	B b1;
	b1.print();

	b1.A::print();
	b1.B::print();//默认情况

	system("pause");//
}

//同名成员变量
void main01()
{
	B b1;
	b1.b = 1;
	
	b.get_child();

	b1.A::b = 100;//全局作用域:: ;修改父类的b
	b1.B::b = 200;//修改子类的b;默认是B

	b1.get();

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
