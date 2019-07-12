#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "algorithm"
#include "list"
//date:2019-06-29 13:03
//Author : null
//Project:list容器模型基本操作

/*
list是一个双向链表容器，可高效地进行插入删除元素
list不可以随机存取元素，所以不支持 at.(pos)函数与[]操作符。it++(ok) it+5(err)
#include <list>
 */

void main71()
{
	lsit<int> l;
	cout<<"list的大小: "<<l.size()<<endl;
	for(int i = 0;i < 10;i++)
	{
		l.push_back(i);//尾部插入元素 尾插法
	}
	//插入之后
	cout<<"list的大小: "<<l.size()<<endl;

	list<int>::iterator it = l.begin();

	while(it != l.end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;

	//list 不能随机访问
	// 0 1 2 3 4 5
	// ▲
	// 		 ▲
	it = l.begin();
	it ++;
	it ++;
	it ++;
	//it = it + 5; //编译错误 不支持随机的访问容器
	
	list.insert(it,100);// 100 插入在哪个位置 

	//result 100 插在了3前面 
	
	//结论:
	//1、链表的结点index 序号是从0号开始的
	//2、在3号位置插入元素，让原来的3号位置变成4号位置 原来的4号位置变成5号位置

	for(list<int>::iterator it = l.begin(),it!=l.end();it++)
	{
		cout<<*it<<" ";
	}

}

//list 删除
void main72()
{
	lsit<int> l;
	cout<<"list的大小: "<<l.size()<<endl;
	for(int i = 0;i < 10;i++)
	{
		l.push_back(i);//尾部插入元素 尾插法
	}
	//插入之后
	cout<<"list的大小: "<<l.size()<<endl;


	// 0 1 2 3 4 5
	// 		 ▲

	list<int>::iterator it1 = l.begin();
	list<int>::iterator it2 = l.begin();

	it2++;
	it2++;
	it2++;

	l.erase(it1,it2);	

	for(list<int>::iterator it = l.begin(),it!=l.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	l.insert(l.begin(),100);
	l.insert(l.begin(),100);
	l.insert(l.begin(),100);

	l.erase(l.begin());

	l.remove(100);
	
	for(list<int>::iterator it = l.begin(),it!=l.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void main()
{
	main71();

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}