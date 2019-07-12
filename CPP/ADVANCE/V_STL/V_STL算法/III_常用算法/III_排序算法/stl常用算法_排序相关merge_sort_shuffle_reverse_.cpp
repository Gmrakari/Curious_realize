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

//date:2019-07-06 15：35
//Author : null
//Project:stl常用算法_排序相关merge_sort_shuffle_reverse_
void printV(vector<int> &v)
{
	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
}

void main_merge()
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

	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

	printV(v3);

}
class Student
{
public:
	Strudent(string name,int id) //有参的构造函数
	{
		m_name = name;
		m_id = id;
	}
	void printT()
	{
		cout<<"name: "<<m_name<<"id: "<<m_id<<endl;
	}
protected:
public:
	string m_name;
	int m_id;
private:

};

bool CompareS(Student &s1,Student &s2)
{
	return (s1.m_id < s2.m_id);
}

void main_sort()
{
	Student s1("老大",1);
	Student s2("老二",2);
	Student s3("老三",3);	
	Student s4("老四",4);

	vector<Student> v1;

	v1.push_back(s4);
	v1.push_back(s1);
	v1.push_back(s3);
	v1.push_back(s2);	

	for(vector<Student>::iterator it = v1.begin(); it!=v1.end();it++)
	{
		it->printT();
	}

	//sort 根据自定义函数对象 进行自定义数据类型的排序
	//替换 算法的统一性 （实现算法和数据类型的分离）====>技术手段函数对象
	sort(v1.begin(),v1.end(),CompareS);//CompareS 是一个谓词

	//After sort cout result
	for(vector<Student>::iterator it = v1.begin(); it!=v1.end();it++)
	{
		it->printT();
	}
}

void main_shuffle()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	random_shuffle(v1.begin(),v1.end());

	printV(v1);		//result 1 3 7 5


	string str = "abcdefg";
	random_shuffle(str.begin(),str.end());
	cout<<"str: "<<str<<endl;

}

void main_reverse()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	reverse(v1.begin(), v1.end());

	printV(v1);

}


int main()
{
	main_merge();
	main_sort();
	main_shuffle();
	main_reverse();
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	