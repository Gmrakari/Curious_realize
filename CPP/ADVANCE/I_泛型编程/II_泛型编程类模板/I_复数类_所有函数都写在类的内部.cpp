#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-11-22 16 : 05 
//Author : null
//复数类_所有函数都写在类的内部

template<typename T>
class Complex
{
	friend ostream & operator<<(ostream &out,Complex &c3)
	{
		out<<c3.a<<" + "<<c3.b<<" i"<<endl;
	}
	friend Complex MySub(Complex &c1,Complex &c2)
	{
		Complex tmp(c1.a - c2.a ,c1.b - c2.b);
		return tmp;
	}
public:
	Complex(T a ,T b)
	{
		this->a = a;
		this->b = b;
	}
	Complex operator + (Complex &c2)
	{
		Complex tmp(a + c2.a,b + c2.b);
		return tmp;
	}
	operator<<(ostream &out,Complex &c3)
	{
		out<<"a: "<<c3.a<<"b: "<<c3.b<<endl;
		return out;
	}
	void printCom()
	{
		cout<<"a: "<<a<<"b: "<<b<<endl;
	}

protected:
private:
	T a;
	T b;
};
//运算符重载的正规写法
//重载 << >> 只能用友元函数，其它运算符重载 都要写成 成员函数 ，不要滥用 友元函数

//error 实用类 模板 需要模板 参数列表 -- 类的内部 
/*	operator<<(ostream &out,Complex &c3)
	{
		out<<"a: "<<c3.a<<"b: "<<c3.b<<endl;
		return out;
	}*/

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