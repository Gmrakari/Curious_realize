#include "iostream"
using namespace std;
//Date:2018-08-30 15：34
//Author:null
//类的封装
//
//封装的两层含义
//1、把属性和方法进行封装
//2、对属性和方法进行访问控制
//3、类的内部和类的外部

//4、类的访问控制关键字
//public: 修饰的成员变量和函数 ， 可以在类的内部 和 类的外部访问
//oritected:  修饰的成员变量和函数 ， 只能在类的内部被访问 ， 不能被类的外部访问
//private: 修饰的成员变量和函数 ， 只能在类的内部被访问 ，不能再类的外部访问 用再继承里面


//求圆的面积
//
class MyCircle{
public:
	double m_r;//属性 成员变量
	double m_s;
public:
	double getR()
	{
		return m_r;
	}
	void setR(double r)//成员函数
	{
		m_r = r;
	}
	double getS()
	{
		m_s = 3.14*m_r*m_r;
	}
protected:
private:
};

//类封装的威力
//类封装的成员变量和成员函数
//类封装的成员变量和成员函数  //可以调用类的函数

void printCircle01(MyCircle *pC)
{
	cout<<"r"<<pC->getR()<<endl;
	cout<<"s"<<pC->getS()<<end1;
}

void printCircle02(MyCircle &myc)
{
	cout<<myc.getS()<<endl;
}

void printCircle03(MyCircle myc)
{

}

void main_类的封装第一层含义()
{
	MyCircle c1,c2;
	c1.setR(10);
	cout<<"c1s:"<<c1.getS()<<endl;
	
	c1.setR(11);
	printCircle01(&c1);

	c2.setR(20);
	printCircle01(&c2);

	//引用
	printCircle02(c2)

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}

class MyadvCircle{
	//不输入任何修饰符 默认是private 
private:
	double m_r;//属性 成员变量
	double m_s;//相当于你们的账户 密码 
public:
	double getR()//相当于一个名字。谁都可以喊
	{
		return m_r;
	}
	void setR(double r)//成员函数
	{
		m_r = r;
	}
	double getS()
	{
		m_s = 3.14*m_r*m_r;
	}
protected:
private:
};

void main_对属性和方法进行访问控制()
{
	MyadvCircle c1,c2;

	c1.m_r = 10;
	cout<<"helloc"<<endl;
	system("pause");
	return 0;	
}


struct AAA
{
	int a;//用struct 关键字定义的类 ，不写 ，默认的属性是public 的
public:
protected:
private:

};

void main_stuct_class_different()
{
	struct AAA a1;
	a1.a = 10;
	cout<<"helloc"<<endl;
	system("pause");
	return 0;	
}