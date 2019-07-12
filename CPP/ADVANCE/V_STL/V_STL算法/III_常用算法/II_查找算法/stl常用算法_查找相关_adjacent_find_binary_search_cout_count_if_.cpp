#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include <vector>
#include "algothrim"

//date:2019-07-06 14:23
//Author : null
//Project:stl常用算法_查找相关_adjacent_find_binary_search_cout_count_if_

void main44_adjacent_find()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);

	vector<int>::iterator it = adjacent_find(v1.begin(),v1.end());

	if(it == v1.end())
	{
		cout<<"没有找到 重复的元素"<<endl;
	}
	else
	{
		cout<<*it<<endl;
	}
	int index = distance(v1.begin(),it);
	cout<<index<<endl;

}

// 0 1 2 3 ... n-1
// 二分法 1k = 1024 10次
void main45_binary_search()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);

	bool b = binary_search(v1.begin(),v1.end(),7);	
	if(b == true)
	{
		cout<<"找到了"<<endl;
	}
	else
	{
		cout<<"没有找到"<<endl;
	}

}

void main46_cout()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(7);

	int num = cout(v1.begin(),v1.end(),7);	
	cout<<num<<endl;
}

bool GreatThree(int iNum)
{
	if(iNum > 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void main47_count_if()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(7);

	int num = cout_if(v1.begin(),v1.end(),GreatThree);	

	cout<<"num:"<<num<<endl;	
}

void main48_find()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(7);

	vector<int>::iterator it = find(v1.begin().v1.end(),5);
	cout<<"*it:"<<*it<<endl;
}

int main()
{
	//main44_adjacent_find();

	//main45_binary_search();

	//main46_cout();

	//main47_count_if();

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}