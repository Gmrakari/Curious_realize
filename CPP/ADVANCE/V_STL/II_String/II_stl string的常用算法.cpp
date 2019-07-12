#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2019-06-27 09：15
//Author : NULL
//Project:stl string的常用算法


void main27()
{
	string s1 = "AAAbbb";
	//1、函数的入口地址 函数对象 预定义的函数
	transform(s1.begin(),s1.end(),s1.begin(),toupper);
	cout<<"s1: "<<s1<<endl;

	string s2 = "AAAAbbb";

	transform(s2.begin(),s2.end(),s2.begin(), tolower);

	cout<<"s2: "<<s2<<endl;
}

void main()
{
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}