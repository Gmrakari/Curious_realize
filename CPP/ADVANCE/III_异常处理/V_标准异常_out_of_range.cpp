#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
#include "string"
#include <stdexcept> 
using namespace std;

//date:2018-12-09 11 : 47
//Author : null
//Project:标准异常_out_of_range

class Teacher
{
public:
	Teacher(int age)
	{
		if(age > 100)
		{
			string s = "年龄太大";
			throw out_of_range(s);
		}
		this->age = age;
	}
protected:
private:
	int age;
};

void main1()
{
	try
	{
		Teacher t1(102);
	}
	catch (out_of_range e)
	{
		cout<<e.what()<<endl;
	}
	exception e;
	system("pasue");
}

class MyException : public exception
{
public:
	MyException(const char *p)
	{
		this->m_p = p;
	}
	virtual const char * what()
	{
		cout<<"MyException：类型异常"<<m_p <<endl;
		return m_p;
	}
protected:
private:
	const char *m_p;
}

void testMyecept()
{
	throw MyException("函数异常");
}

void main()
{
	try
	{
		testMyecept();
	}
	catch(MyException & e)
	{
		e.what();
	}
	catch(...)
	{
		cout<<"未知类型"<<endl;
	}
	system("pause");

}

