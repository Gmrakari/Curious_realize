#include "iostream"
using namespace std;

//date:2018-10-22 19:50
//Author : null
//类型兼容性原则


//类型兼容原则
/*类型兼容规则指在需要基类对象的任何地方，都可以使用公有派生类的对象来替代。

子类对象可以当作父类对象 

子类对象可以直接赋值给父类对象

子类对象可以直接初始化父类对象

父类引用可以直接引用子类对象*/

class Parent
{
public:
	void printP()
	{
		cout<<"我是父类"<<endl;
	}
private:
	int a;

};

class child:public Parent
{
public:
	void printC()
	{
		cout<<"我是子类"<<endl;
	}
private:
	int c;

};

//Cpp编译器 不会报错
void howtoPrint(Parent *base)
{
	base->printP();//父类的 成员函数
}

void howtoPrint2(Parent &base)
{
	base.printP();//父类的 成员函数
}


void main()
{
	Parent p1;
	p1.printP();

	child c1;
	c1.printC();

	c1.printP();

	//赋值兼容性原则
	//1-1 基类指针（引用） 指向  之类对象
	
	Parent *p = NULL;

	p = &c1;
	p->printP();

	//1-2 指针做函数参数
	
	howtoPrint(&p1);
	howtoPrint(&c1);

	//1-3 引用做函数参数
	
	howtoPrint(p1);
	howtoPrint(p2);

	//第二层含义
	
	//可以让父类对象 初始化 子类对象
	//子类就是一种特殊的父类
	Parent p3 = c1;

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}




