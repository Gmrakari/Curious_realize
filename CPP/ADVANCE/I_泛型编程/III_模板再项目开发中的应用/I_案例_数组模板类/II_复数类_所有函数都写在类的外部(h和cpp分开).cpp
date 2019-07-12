#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-2 11 : 56
//Author : null
//Project:复数类_所有函数都写在类的外部(h和cpp分开)
//

template <typename T>
class Complex;//类的前置 声明

template<typename T>
friend Complex<T> MySub(Complex<T> &c1,Complex<T> &c2);


template<typename T>
class Complex
{
	friend Complex MySub<int>(Complex &c1,Complex &c2);

	friend ostream & operator<< <T>(ostream &out ,Complex &c3);//<T>
public:
	Complex(T a,T b);
	void printCom();
	Complex operator+ (Complex &c2);
/*	Complex operator- (Complex &c2);*/
private:
	T a;
	T b;
};

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
	

void main()
{
	Complex<int> c1(1,2);
	Complex<int> c2(3,4);

	Complex<int> c3 = c1 + c2;

	cout<< c3 <<endl;

	{
		Complex<int>c4 = MySub<int>(c1,c2);//友元函数调用 必须写成
		cout<< c4 << endl;
	}
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}