#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-11-22 17 : 05 
//Author : null
//复数类_所有函数都写在类的外部

template<typename T>
class Complex
{
	friend ostream & operator<<(ostream &out,Complex &c3)
	{
		out<<c3.a<<" + "<<c3.b<<" i"<<endl;
	}
	friend Complex MySub(Complex &c1,Complex &c2);
public:
	Complex(T a ,T b);
	Complex operator + (Complex &c2);
	void printCom();

protected:
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
	cout<<"a: "<<a<<"b: "<<b<<endl;
}

//成员函数 实现 + 运算符重载
template<typename T>
Complex<T> Complex<T>::operator + (Complex &c2)
{
	Complex tmp(a + c2.a , b + c2.b);
	return tmp;
}

//友元函数 实现<< 运算符重载
template<typename T>
ostream & operator<<(ostream &out,Complex<T> &c3)
{
	out<<c3.a<<" + "<<c3.b<<" i"<<endl;
	return out;
}

void main()
{
	//需要把模板类 进行具体化以后 才能定义对象 cpp编译器要分配内存
	Complex<int> c1(1,2);

	Complex<int> c2(3,5);
	complex<int> c3 = c1 + c2;
	/*c3.printCom();*/

	cout<<c3<<endl;

	//滥用友元函数
	{
		Complex<int> c4 = MySub(c1,c2);
		cout<<c4<<endl;
	}

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}