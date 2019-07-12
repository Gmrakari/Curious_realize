#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "string"
#include <vector>
#include <list>
#include "set"
#include <algorithm>
#include "functional"
#include "iterator"

//date:2019-07-06 16:00
//Author : null
//Project:stl常用算法_拷贝和替换相关main52_copy_main53_replace_main54_replace_raplaceif_main55_swap_
void printV(vector<int> &v)
{
	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
}

void main52_copy()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2;

	v2.resize(v1.size());

	copy(v1.begin(),v1.end(),v2.begin());

	printV(v2);
}

void main53_replace()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(3);	

	replace(v1.begin(),v1.end(),3,8);
	printV(v1); //=====> 3 变成 8
}

bool great_equal_5(int &n)
{
	if(n >= 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void main54_replace_raplaceif()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(3);	

	replace(v1.begin(),v1.end(),3,8);
	printV(v1); //=====> 3 变成 8

	// >=5 
	replaceif(v1.begin(),v1.end(),3,1);
	printV(v1); //=====> result 11111
}

void main55_swap()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);	

	swap(v1,v2);//将v1 变成v2;
	printV(v1); //result ====>2 4 6

}

int main()
{
	main52_copy();
	main53_replace();
	main54_replace_raplaceif();
	main55_swap();
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}