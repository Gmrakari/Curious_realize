#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "complex.h"

//date:2018-12-02 11 : 55 
//Author : null
//Project:复数类_所有函数都写在类的外部(h和cpp分开)

template<typename T>
Complex<T>::Complex(T a,T b)
{
	this->a = a;
	this->b = b;
}

template<typename T>
void Complex<T>::printCom()
{
	cout<<"a:"<<a<<"b:"<<b<<endl;
}

// 本质 是 模板是两次 编译生成的 第一次生成的函数头 和 第二次生成的函数头 不一样
//成员函数 实现+ 运算符重载
template<typename T>
Complex<T> Complex<T>::operator+ (Complex<T> &c2)//函数的参数需要具体化
{
	Complex<T> tmp(a + c2.a,b + c2.b);
	return tmp;
}



//友元函数 实现 <<运算符重载
ostream & operator<<(ostream &out ,Complex<T> &c3)
{
	out<<c3.a<<"+"<<c3.b <<"i"<< endl;
	return out;
}


//------------------------------------------------------//
//滥用友元函数
template <typename T>
Complex<T> MySub(Complex<T> &c1,Complex<T> &c2)
{
	Complex tmp(c1.a - c2.a ,c1.b - c2.b);
	return tmp;
}

