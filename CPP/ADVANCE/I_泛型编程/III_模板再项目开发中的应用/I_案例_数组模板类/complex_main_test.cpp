#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "complex.h"
#include "complex.cpp"

//date:2018-12-02 11 : 55 
//Author : null
//Project:复数类_所有函数都写在类的外部(h和cpp分开)

void main()
{
		
	Complex<int> c1(1,2);
	Complex<int> c2(3,4);

	Complex<int> c3 = c1 + c2;

	cout<< c3 <<endl;

	//滥用友元函数
	{
		Complex<int>c4 = MySub<int>(c1,c2);//友元函数调用 必须写成
		cout<< c4 << endl;
	}

	

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}