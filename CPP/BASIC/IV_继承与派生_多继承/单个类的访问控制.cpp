#include "iostream"
using namespace std;

//date:2018-10-22 15：30
//Author : null
//单个类的访问控制


/*public:修饰的成员变量 方法 在类的内部 类的外部都能使用
protect: 修饰的变量成员，在类的内部使用。在继承中使用/
private:修饰的成员变量方法 只能在类的内部使用 不能在类的外部*/

/*cpp中的继承方式(public/private/protected)会影响子类的对外访问属性
判断某一句话 ，能否被访问
三看原则
1、看调用的语句，这句话写在子类的内部、外部
2、看子类如何从父亲继承(public/private/protected)
3、看父类中的访问级别(public/private/protected)
*/

class Test
{
public:
	int a;
protected:
	int b;
private:
	int c;
public:
	void printT()
	{
		cout<<"printT"<<endl;
	}
};

class Chile:public Parent
{
public:
	void useVar()
	{
		a = 0;//编译通过
		b = 0;//编译通过
		c = 0;//编译error
	}
protected:
private:
};
//保护继承
class Child3:protected Parent
{
public:
protected:
private:
public:
	void usevar()
	{
		a = 0;//ok
		b = 0;//ok, b在这里 写在了子类的Child3的内部，2看protected 3密码===>protected
		c = 0;//error
	}

}
//私有继承
class Chile2:private Parent
{
public:
	void useVar()
	{
		a = 0;//编译通过
		b = 0;//编译通过
		c = 0;// error
	}
protected:
private:
};


void main01()
{
	Parent t1,t2;
	t1.a= 10;//编译通过
	t1.b = 20;//

	t2.c = 30;
	Test t1,t2;
}

void main02()
{
	int 
}


void main03()
{
	Child3 c3;
	c3.a = 10;//error
	c3.b = 20;//error
	c3.c = 30;//error

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
