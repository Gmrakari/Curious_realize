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

#include <numeric>

//date:2019-07-06 16:33
//Author : null
//Project:stl常见算法_集合算法union_set_intersection_set_difference_

/*
set_union:够高一个有序序列，包含两个有序序列的并集
set_intersection:构造一个有序序列，包含两个有序序列的交集
set_difference:构造一个有序序列，该序列保留第一个有序序列中存在而第二个有序序列中不在的元素
*/

void printV(vector<int> &v)
{
	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
}

void main57_union()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);	

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	printV(v3); //result ===> 1 2 3 4 5 6
}

//交集
void main_set_intersection()
{
	vector<int> vecIntA;
	vecIntA.push_back(1);
	vecIntA.push_back(3);
	vecIntA.push_back(5);
	vecIntA.push_back(7);
	vecIntA.push_back(9);

	vector<int> vecIntB;
	vecIntB.push_back(1);
	vecIntB.push_back(3);
	vecIntB.push_back(5);
	vecIntB.push_back(6);
	vecIntB.push_back(8);

	vector<int> vecIntC;
	vecIntC.resize(10);


	//交集
	fill(vecIntC.begin(),vecIntC.end(),0);
	set_intersection(vecIntA.begin(), vecIntA.end(), vecIntB.begin(), vecIntB.end(), vecIntC.begin());		//vecIntC: {1,3,5,0,0,0,0,0,0,0}
	printV(vecIntC);
}

//差集
void main_set_difference()
{
	vector<int> vecIntA;
	vecIntA.push_back(1);
	vecIntA.push_back(3);
	vecIntA.push_back(5);
	vecIntA.push_back(7);
	vecIntA.push_back(9);

	vector<int> vecIntB;
	vecIntB.push_back(1);
	vecIntB.push_back(3);
	vecIntB.push_back(5);
	vecIntB.push_back(6);
	vecIntB.push_back(8);

	vector<int> vecIntC;
	vecIntC.resize(10);

	//差集
	fill(vecIntC.begin(),vecIntC.end(),0);
	set_difference(vecIntA.begin(), vecIntA.end(), vecIntB.begin(), vecIntB.end(), vecIntC.begin());			//vecIntC: {7,9,0,0,0,0,0,0,0,0}
	printV(vecIntC);
}
	

int main()
{
	main57_union();
	main_set_intersection();//交集
	main_set_difference();//差集

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}