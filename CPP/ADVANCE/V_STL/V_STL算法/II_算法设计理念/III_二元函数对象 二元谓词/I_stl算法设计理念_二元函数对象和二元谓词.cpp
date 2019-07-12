#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2019-07-04 10：44
//Author : null
//Project:stl算法设计理念_二元函数对象和二元谓词

template <template T>
class SumAdd
{
public:
	T operator()(T t1,T t2)
	{
		return t1 + t2;
	}
	privated:
protected:
	
};
void main04()
{
	//v1 v2 ==>v3
	vector<int> v1,v2;
	vector<int> v3;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(10);

	transform(v1.begin(),v1.end(),v2.begin(),v3.begin(),SumAdd<int>());

	for(vector<int>::iterator it = v3.begin();it++)
	{
		cout<<*it<<endl;
	}
	cout<<endl;

	for_each(v1.begin(),v1.end(),FUncShowElemt2);

	cout<<endl;

	sort(v1.begin(),v1.end(),My)
}

bool Mycompare(const int &a,const int &b)
{
	
}

void main05()
{
	vector<int> v1(10);

	for(int i = 0;i<10;i++)
	{
		int tmp = rand()%100; 
	}
}

void main()
{
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}