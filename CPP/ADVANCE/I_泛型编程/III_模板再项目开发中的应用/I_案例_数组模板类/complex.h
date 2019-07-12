#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#pragma once 
//date:2018-12-02 11 : 55 
//Author : null
//Project:复数类_所有函数都写在类的外部(h和cpp分开)

template<typename T>
class Complex
{
	friend Complex MySub<int>(Complex &c1,Complex &c2);

	friend ostream & operator<< <T>(ostream &out ,Complex &c3);//注意<T>
public:
	Complex(T a,T b);
	void printCom();
	Complex operator+ (Complex &c2);
/*	Complex operator- (Complex &c2);*/
private:
	T a;
	T b;
};