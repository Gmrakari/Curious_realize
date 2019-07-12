#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
//date:2019-03-31 19：12
//Author : null
//Project:STL容器算法迭代器入门

void main11()
{
	vector<int> v1;	//	1容器 ：把你的元素copy到容器中
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	// 1 3 5
	// 2迭代器：相当于一个 指针 分类
	for(vector<int>::iterator it = v1.begin();it != v1.end();it++)
	{
		cout<<*it<<" ";
	}

	//3算法	算法和迭代器 进行无缝的连接 
	int num = count(v1.begin(),v1.end(),3);
	cout<<"num1: "<<num1<<endl;
}

class Teacher
{
public:
	int age;
	char name[64];
public:
	void printT()
	{
		cout<<"age: "<<age<<endl;
	}
};

//容器中 装元素
void main12()
{
	Teacher t1,t2,t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	Teacher *p1,*p2*p3;

	p1 = &t1;
	p2 = &t2;
	p3 = &t3;


	vector<Teacher *> v1;	//	1容器 ：把t1 t2 t3内存首地址 放入到了容器

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);

	// 1 3 5
	// 2迭代器：相当于一个 指针 分类
	for(vector<int>::iterator it = v1.begin();it != v1.end();it++)
	{
		cout<<(*it)->age <<" ";
	}

	//如何求 容器中 老师结点的 年龄 = 33 个数

	//3算法	算法和迭代器 进行无缝的连接 
	int num = count(v1.begin(),v1.end(),3);
	cout<<"num1: "<<num1<<endl;
}



void main()
{
	main11();


	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}