#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include <MyVector.cpp>
//date:2018-12-02 16 : 25 
//Author : null
//数组模板类_数组元素存储的是类对象思想
class Teacher
{
public:
	Teacher()
	{
		age = 33;
		strcpy(name,"");
	}

	Teacher(char *name ,int age)
	{
		this->age = age;

		strcpy(this->name,name);
	}
	void printT()
	{
		cout<<name<<", "<<age<<endl;
	}
protected:
private:
	int age;
	char name[32];
};

void main(int argc, char const *argv[])
{
	/* code */
	Teacher t1("t1",31),t2("t2",32),t3("t3",33),t4("t4",34);

	MyVector<Teacher> tArray(4);

	tArray[0] = t1;
	tArray[1] = t2;
	tArray[2] = t3;
	tArray[3] = t4;

	for(int i = 0;i < 4 ;i++)
	{
		Teacher tmp = tArray[i];
		tmp.printT();
	}

	system("pause");
	return 0;
}

void main02()
{
	MyVector<char> myv1(10);
	//下面给元素赋值
	//方法一
/*	for(int i = 97;i< my1.getLen();i++)
	{
		myv1[i] = 97;
		cout<<myv[i]<<" ";
	}*/
	//方法二
	myv[0] = 'a';
	myv[1] = 'b';
	myv[2] = 'c';
	myv[3] = 'd';

	cout<<myv1;
	system("pause");

}

void main01()
{
	MyVector<int> myv1(10);
	for(int i = 0;i< my1.getLen();i++)
	{
		myv1[i] = i + 1;
		cout<<myv[i]<<" ";
	}
	cout<<endl;

	MyVector<int> myv2 = myv1;

	for(int i = 0;i <myv.getLen();i++)
	{
		cout<<myv2[i]<<" ";
	}

	cout<<myv2 <<endl;
	operator<<(ostream &out,MyVector &obj)


	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}