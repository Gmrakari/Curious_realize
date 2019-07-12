#include "iostream"
using namespace std;

//date:2018-10-27 17:22
//Author : null
//多继承的二义性和虚继承解决方案


 class B
 {
 public:
 	int b;
 protected:
 private:
 };

class B1:virtual public B
{
public:
	int b1;
};

class B2:virtual public B
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

/*	c1.b = 500;//访问不明确，编译器报错*/

	//继承解决方案 声明的时候添加一个virtual 关键字
	c1.b = 500;

	cout<<"hellc"<<endl;
	system("pause");
}
