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

//date:2019-07-06 16:23
//Author : null
//Project:stl常见算法_算法和生成accumulate_fill_

void printV(vector<int> &v)
{
	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
}

void main_accumulate()
{
	vector<int> vecIntA;
	vecIntA.push_back(1);
	vecIntA.push_back(3);
	vecIntA.push_back(5);
	vecIntA.push_back(7);
	vecIntA.push_back(9);	

	int iSum = accumulate(vecIntA.begin(),vecIntA.end(),100);
	printV(vecIntA);
}

//fill 将输入值赋给标志范围内的所有元素 	
void main_fill()
{
	vector<int> vecIntA;
	vecIntA.push_back(1);
	vecIntA.push_back(3);
	vecIntA.push_back(5);
	vecIntA.push_back(7);
	vecIntA.push_back(9);

	fill(vecIntA.begin(),vecIntA.end(),8); //result 8,8,8,8,8
	printV(vecIntA);			
}
int main()
{
	main_accumulate();
	main_fill();
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}