#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "deque"
#include "algorithm"
//date:2019-06-29 11：34
//Author : null
//Project: deque容器的基本操作
//双端数组

void printD(deque<int> &d)
{
	for(deque<int>::iterator it = d.begin();it !=d.end();it++)
	{
		cout<<*it<<" ";
	}
}

void main41()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(3);
	d1.push_back(5);

	d1.push_front(-11);
	d1.push_front(-33);
	d1.push_front(-55);
	cout<<endl;

	cout<<"头部元素: "<<d1.front()<<endl;
	cout<<"尾部元素: "<<d1.back()<<endl;
	printD(d1);

	d1.pop_front();
	d1.pop_back();

	printD(d1);

	//查找 -33 在数组下标的值
	deque<int>::iterator it = find(d1.begin(),d1.end(),-33);

	if(it !=d1.end())
	{
		cout<<"-33数组下标是"<<distance(d1.begin(),it)<<endl;
	}
	else
	{
		cout<<"没有找到-33的元素"<<endl;
	}
}


void main()
{
	main41();
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	
