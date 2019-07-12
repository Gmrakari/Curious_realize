#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "set"
//date:2019-06-29 16:38
//Author : null
//Project: set容器_find查找_equal_range(pair的使用)

void main95()
{
	set<int> set1;



	for(int i = 0;i < 10 ;i++)
	{
		set1.insert(i + 1);
	}

	//从大到小
	for(set<int,greater<int>>::iterator it = set1.begin();it != set1.end();it++)
	{
		cout<<*it<<endl;
	}
	cout<<endl;

	set<int>::iterator it0 = set1.find(5);
	cout<<"it0 "<<*it0<<endl;

	int num1 = set1.count(5);
	cout<<"num1: "<<num1<<endl;

	set<int>::iterator it1 = set1.lower_bound(5);//大于等于5的元素 的 迭代器的位置
	cout<<"it1:"<<*it1<<endl;

	set<int>::iterator it2 = set1.lower_bound(5);//大于的元素 的 迭代器的位置
	cout<<"it1:"<<*it2<<endl;	

/*	typedef pair<iterator,bool> _Pairib;
	typedef pair<iterator,iterator> _Pairii;
	typedef pair<const_iterator,const_iterator> _Paircc;*/
	
	pair<set<int>::iterator,set<int>::iterator> mypair = set1.equal_range(5);
	set<int>::iterator it3 = mypair.first;
	cout<<"it3:"<<*it3<<endl;//5 //6

	set<int>::iterator it4 = mypair.second;
	cout<<"it4:"<<*it4<<endl;//6 //6


}

void main()
{

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}