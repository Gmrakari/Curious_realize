//Date:2018-08-28
//Author:gm_zzy
//inline内联函数
#include "iostream"
using namespace std;

//说明一、inline和函数体的实现，写在一块
//inline void printA();


inline void printA()
{
	int a = 10;
	cout<<"a"<<a<<endl;
}

void main()
{
	printA();
	//说明二、cpp编译器直接将行数提插入在函数调用的地方
	//说明三、cpp编译器不一定准许函数的内联请求
	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
