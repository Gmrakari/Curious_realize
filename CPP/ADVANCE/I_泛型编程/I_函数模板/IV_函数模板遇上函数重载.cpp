#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-11-20 19:53
//Author : null
//函数模板遇上函数重载


//让 类型参数化 ===, 方便程序员进行编码
//泛型编程
//template 告诉cpp编译器 我要开始泛型编程了，看到T，不要随便报错
template<typename T>
void myswap(T &a,T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
	cout<<"调用myswap"<<;
}

void myswap(int a,char c)
{
	cout<<"a:"<<a<<"c: "<<c<<endl;

	cout<<"我是普通函数"<<endl;
}


void main()
{ 
	int a = 10;
	char c = 'z';

	myswap(a,c);//普通函数的调用:可以进行 隐式的类型转化

	myswap(c,a);//

	myswap(a,a);//调用函数模板(本质:类型参数化),将严格的按照类型进行匹配，不会进行自动类型转换




	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}