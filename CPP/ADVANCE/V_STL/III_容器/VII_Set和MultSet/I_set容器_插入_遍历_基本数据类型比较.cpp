#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "set"
//date:2019-06-29 15:02
//Author : null
//Project:set容器_插入_遍历_基本数据类型比较

//1、集合 元素唯一 自动排序(默认情况下 从小到大) 不能按照[]方式插入元素
//红黑树
//set 插入元素 删除集合
void main91()
{
	set<int> set1;

	for(int i = 0;i < 5 ;i++)
	{
		int tmp =rand();
		set1.insert(tmp);
	}

	//插入元素 
	set1.insert(100);
	set1.insert(100);
	set1.insert(100);

	for(set<int>::iterator it = set1.begin();it!=set1.end();it++)
	{
		cout<<*it<<" ";
	}

	//删除集合
	while(!set1.empty())
	{
		set<int>::iterator it = set1.begin();
		cout<<*it<<" ";
		set1.erase(set1.begin());
	}	
}

void main92()
{
	set<int> set1;
	set<int,less<int>> set2;//默认情况

	set<int,greater<int>> set3;//从大 到 小


	for(int i = 0;i < 5 ;i++)
	{
		int tmp =rand();
		set3.insert(tmp);
	}

	//从大到小
	for(set<int,greater<int>>::iterator it = set3.begin();it != set3.end();it++)
	{
		cout<<*it<<endl;
	}

}

//对于复杂的数据类型 Teacher Student


void main()
{
	main91();
	main92();

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}