#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-11-20 19:53
//Author : null
//函数模板和普通函数在一起调用规则研究

/*
	函数模板不允许自动类型转化
	普通函数能够进行自动类型转换
 */

/*
	1、函数模板可以像普通函数一样被重载
	2、Cpp编译器优先考虑普通函数
	3、如果函数模板可以产生一个更好的匹配，那么选择模板
	4、可以通过空模板实参列表的语法限定编译器只通过模板匹配
 */

int Max(int a,int b)
{
	cout<<"int Max(int a,int b)"<<endl;
	return a>b?a:b;
}
//让 类型参数化 ===, 方便程序员进行编码
//泛型编程
//template 告诉cpp编译器 我要开始泛型编程了，看到T，不要随便报错
template<typename T>
T Max(T a,T b)
{
	cout<<"T Max(T a,T b)"<<endl;
	return a>b?a:b;
}

template<typename T>
T Max(T a,T b,T c)
{
	cout<<"T Max(Ta ,T b, T c)"<<endl;
	return Max(Max(a,b),c);
}

void main()
{
	int a = 1;
	int b = 2;

	cout<<Max(a,b)<<endl; //当函数模板和普通函数都符合调用时，优先选择普通函数
	cout<<Max<>(a,b)<<endl;// 若显示使用函数模板，则使用<>类型列表

	cout<<Max(3.0,4.0)<<endl;// 如果 函数模板产生更好的匹配 使用函数模板

	cout<<Max(5.0,6.0,7.0)<<endl;// 重载

	cout<<Max('a',100)<<endl; //调用普通函数 可以隐式类型转换  //函数模板需要一定的规则>>

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}


