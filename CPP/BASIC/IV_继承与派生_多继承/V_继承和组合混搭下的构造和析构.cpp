#include "iostream"
using namespace std;

//date:2018-10-22 21：14
//Author : null
//继承和组合混搭下的构造和析构

class Objecet
{
public:
	Object(int a,int b)
	{
		this->a = a;
		this->b = b;
		cout<<"object 构造函数 执行"<<"a"<<a<<"b"<<b<<endl;
	}
	~Object()
	{
		cout<<"object析构函数"<<endl;
	}
protected:
	int a;
	int b;
};

class Parent:public Object
{
public:
	Parent(char *p):Object(1,2)
	{
		this->p = p;
		cout<<"父类构造函数..."<<p<<endl;
	}
	~Parent()
	{
		cout<<"构造函数.."<<endl;
	}
	void printP(int a,int b)
	{

		cout<<"我是父类"<<endl;
	}
protected:
	char *p;
private:
	int a;
	int b;
};

class child:public Parent
{
public:
	child(char *p):Parent(p),obj1(3,4),obj2(5,6)
	{
		this->myp = p;
		cout<<"子类的构造函数"<<myp<<endl;
	}
	~child()
	{
		cout<<"子类的析构函数"<<myp<<endl;
	}
	void printC()
	{
		cout<<"我是子类"<<endl;
	}
protected:
	char *myp;
	Object obj1;
	Object obj2;

};

class child:public Parent
{
public:
	child(int a,int b,int c)
	{
		this->c = c;
	}
	void printC()
	{
		cout<<"我是子类"<<endl;
	}
};

void playobj()
{
	child c1("继承测试");
}

void main()
{

	playobj();
	cout<<"hello..."<<endl;
	system("pause");
	return ;
}