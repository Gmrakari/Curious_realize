#include "iostream"
using namespace std;

//date:2018-10-22 14:30
//Author : null
//继承的多态与基础
//Project：继承的基本语法


/*oo的特点:抽象、封装、继承和多态性*/

/*the contact of class and class*/

/*class A
{
	useA(A &obj)
}*/

//弱包含和强包含关系

/*继承的概念*/

/*继承是类之间定义的一种重要关系
一个B类继承A类，或称从类A派生类B*/

/*基本语法*/

/*class 培生类名：基类名表
{
	数据成员和成员函数声明
};

基类名表 构成
	访问控制 基类名1，访问控制 基类名2，...,访问控制 基类名3
	访问控制表示派生类对基类的继承方式，使用关键字
	public :共有继承
	private：私有继承
	protected 保护继承*/

class Parent
{
	public:
	private:
		int a;
		int b;
	public:
		void print()
		{
			cout<<"a"<<a<<endl;
			cout<<"b"<<b<<endl;
		}
};


class Child: public Parent
{
public:
protected:
private:
	int c;
}
/*class Child: private Parent
class Child: protected Parent*/

void main()
{
	Child c1;
	
	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}


