#include "iostream"
using namespace std;


//date:2018-10-03 12:38
//Author : null
//运算符重载正规的写法

class Complex
{
private:
	int a;
	int b;
	friend void opeartor<<(ostream &out,COmplex &c1);
	friend ostream& opeartor<<(ostream &out,COmplex &c1);
public:
	Complex(int a = 0,int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout<<a<<"+"<<"i"<<endl;
	}

public:
	//实现 + 运算符重载
	Complex operator+(Complex &c2)
	{
		/*Complex tmp(1,2);*/
		Complex tmp(a + c2.a,b + c2.b);
		return tmp;
	}
	//前置++
	Complex& operator++(Complex &c1)
	{
		a++;
		b++;
		return *this;
	}
	//后置++
	Complex operator++(int)
	{
		//先使用 在让c1加
		Complex tmp = *this;
		/*return c1;*/
		this->a ++;
		this->b ++;
		return tmp;
	}
//2、成员函数法 实现 - 运算符重载
public:
	Complex operator - (Complex &c2)
	{
		Complex tmp(this->a - c2.a,this->b - c2.b);
		return tmp;
	}
	//前置--
	Complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}

	//后置--
	Complex operator--(int)
	{
		Complex tmp = *this;
		this->a--;
		this->b--;
		return tmp;
	}

};

/*全局函数、类成员函数方法实现运算符重载步骤
1、要承认操作符重载是一个函数，写出函数名称
2、根据操作数，写出函数参数
根据业务，完善函数返回值（看函数是返回引用 还是指针 元素),及实现函数业务*/
void main()
{
	Complex c1(1,2),c2(3,4);

	Complex c3 = c1 + c2;
	//1、全局函数方法 实现 + 运算符重载
	
	/*operator+(Complex &c1,Complex &c2);*/
	Complex c3 = c1 + c2;
	c3.printCom();

	//2、成员函数法 实现-运算符重载
	
	//c1.operator + (this,c2);

	//Complex operator - (Complex &c2)
	
	Complex c4 = c1 - c2;
	c4.printCom();

	//前置++操作符 用全局函数实现
	++c1;

	Complex& operator++(Complex &c1);

	//前置--操作符 用全局函数实现
	--c1;
	c1.printCom();

	c1.operator--();
	Complex operator--();

	//后置++操作符 用全局函数 实现
	c1++;
	c1.printCom();
	//函数返回值 不是运算符重载的判断标准
	Complex operator++(Complex &c1);

	//后置--操作符 用成员函数实现
	c1--;
	c1.printCom();
	/*c1.operator--();*/
	Complex operator--();


	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}

void opeartor<<(ostream &out,COmplex &c1)
{
	out<<"causal"<<endl;
	out<<c1.a<<"+"<<c1.b<<"i"<<endl;

}
//友元函数的真正用处
ostream& opeartor<<(ostream &out,COmplex &c1)
{
	out<<"causal"<<endl;
	out<<c1.a<<"+"<<c1.b<<"i"<<endl;
	return out;
}

void main()
{
	int a = 10;
	Complex c1(1,2),c2(3,4);
	cout<<a<<endl;//按照数据类型
	//1
	cout<<c1;
	//2 ostream 类中 添加 成员函数.operator<<
	//ostream
	//cout.operator<<(c1);


	//1、2 函数左边引用时，一定要返回一个值
	cout<<c1<<"aaabbbddd";
	//演变过程
	cout.operator(c1).operator<<("aabbbddd");
	aaa.opeartor("aaabbbddd");


	
	system("pause");
}