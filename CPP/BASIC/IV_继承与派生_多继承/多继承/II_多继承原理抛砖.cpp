#include "iostream"
using namespace std;

//date:2018-10-28 11：20
//Author : null
//多继承原理抛砖

class B
 {
 public:
 	B()
 	{
 		cout<<"B的构造函数"<<endl;
 	}
 protected:
 private:
 };

class B1: virtual public B //12
{
public:
	int b1;
};

class B2: public B //8
{
public:
	int b2;
};

class C:public B1,public B2
{
public:
	int c;
}

void main()
{
	C c1;
	c1.b1 = 100;
	c1.b2 = 200;
	c1.c = 300;


	cout<<"hellc"<<endl;
	system("pause");
}

class D1
{
public:
	int k;
protected:
private:	
};

class D2
{
public:
	int k;
protected:
private:
};

class E : virtual public D1,virtual D2
{
public:
protected:
private:

};

class E:public D1,public D2
{
	public:
	protected:
	private:
};

void main02()
{
	E e1;
	e1.D1::k = 100;
	e2.D2::k = 200;

	system("pause");
}

void main03()
{
	cout<<sizeof(B)<<endl;//4
	cout<<sizeof(B1)<<endl;//12 加上vitual 关键字以后，cpp编译器会给变量 偷偷的增加属性
	cout<<sizeof(B2)<<endl;//8  父类一个int ，子类（本身）有一个int 所以是4+4 = 8
	//cout<<sizeof(B)<<endl;
}