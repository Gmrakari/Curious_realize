#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "string"
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

//date:2019-07-06 09：18
//Author : null
//Project:stl算法设计理念，二元谓词在set集合的应用

struct CompareNoCase
{
	bool operator()(const string &str1,const string &str2)
	{
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(),str1.end(),str1_begin(),tolower);//预定义函数对象

		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(),str2.end(),str2_begin(),tolower);//预定义函数对象
		return (str1 < str2);
	}
}

void main06()
{
	set<string> set1;
	set1.insert("bbb");
	set1.insert("aaa");
	set1.insert("ccc");	

	set<string>::iterator it = set1.find("aaa");//find 默认情况下是区分大小写的
	if(it == set1.end())
	{
		cout<<"没有找到aaa"<<endl;
	}
	else
	{
		cout<<"查找到aaa"<<endl;
	}

	set<string,CompareNoCase> set2;
	set2.insert("bbb");
	set2.insert("aaa");
	set2.insert("ccc");

	set<string,CompareNoCase>::iterator it2 = set2.find("aAa");
	if(it2 == set2.end())
	{
		cout<<"没有找到aaa"<<endl;
	}
	else
	{
		cout<<"不区分查找到aaa"<<endl;
	}

}

int main()
{
	void main06();
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}