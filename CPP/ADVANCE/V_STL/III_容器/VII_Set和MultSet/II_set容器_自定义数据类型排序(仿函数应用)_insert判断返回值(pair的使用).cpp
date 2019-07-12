#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "set"
//date:2019-06-29 15:43
//Author : null
//Project:set容器_自定义数据类型排序(仿函数应用)_insert判断返回值(pair的使用)

class Student
{
public:
	Student(char *name,int age)
	{
		strcpy(this->name,name);
		this->age = age;

	}
public:
	char name[64];
	int age;
};

//仿函数
struct FuncStudent
{
	bool operator()(const Student &left,const Student &right)
	{
		if(left.age < right.age)//从小到大 按照年龄排序
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
//typedef pair<iterator,bool> _Pairib;
//如何判断set1.insert函数的返回值
//仿函数的用法
void main93()
{

	Student s1("s1",31);
	Student s2("s2",22);	
	Student s3("s3",44);
	Student s4("s4",11);
	Student s5("s1",31);

	set<Student,FuncStudent> set1;
	pair<set<Student,FuncStudent>::iterator,bool> pair1 = set1.insert(s1);
	if(pair1.second == true)
	{
		cout<<"插入s1成功"<<endl;
	}
	else
	{
		cout<<"插入s1失败"<<endl;
	}
	// set1.insert(s1);
/*	set1.insert(s2); 
	set1.insert(s3);*/
	set1.insert(s4);
	//set1.insert(s5);//如果两个31岁 能插入成功？
	pair<set<Student,FuncStudent>::iterator,bool> pair5 = set1.insert(s5);
		if(pair1.second == true)
	{
		cout<<"插入s1成功"<<endl;
	}
	else
	{
		cout<<"插入s1失败"<<endl;
	}
	//如何知道填 插入的 结果

	//遍历
	for(set<Student,FuncStudent>::iterator it = set1.begin();it!=set1.end();it++)
	{
		cout<<it->age<<"\t"<<it->name<<endl;
	}
}

void main94()
{

}

void main()
{
	main93();
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}