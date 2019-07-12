#include "iostream"
using namespace std;
#include "MyArray.h"
//date:2018-10-04 15:22 
//Author : null
//数组类案例 重载
//Project:2

//类的框架设计完毕
//类的测试案例
void main()
{
	Array a1(10);
	cout<<"输入a1"<<endl;
	for(int i = 0;i<10;i++)
	{
		a1.setData(i,i);
		//
		a1[i] = i;
	}

	cout<<"打印数组a1";
	for(int i = 0;i<a1.length();i++)
	{
		//cout<<a1.getData(i)<<"";
		//1
		cout<<a1[i]<<endl;
	}
	cout<<endl;
	void opeartor[](int i)
	int opeartor[](int i)
	int&opeartor[](int i)

	Array a2 = a1;
	cout<<"输入a2"<<endl;
	for(int i = 0;i<a2.length();i++)
	{
		cout<<a2.getData(i)<<"";
	}

	cout<<endl;
	//3
	{
		Array a3(5);
		a3 = a1;
		a3 = a2 = a1;

		cout<<"\n打印数组a3";
		for(int i = 0;i < a3.length();i++)
		{
			cout<<a3[i]<<" ";
		}

		//a3.operatior=(a1)
		//Array& operator= (Array &a1)
	}

	//功能4
	if(a3 == a1)
	{
		printf("相等")
	}
	else
	{
		cout<<"不相等";
	}

	//a3.opeartor==(a1);
	//bool opeartor == (Array &a1);

	if(a3 != a1)
	{
		printf("不相等\n");
	}
	else
	{
		cout<<"\n相等";
	}
	//
	//a3.operator!=(a1);
	//bool operator!=(Array &a1);

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}




