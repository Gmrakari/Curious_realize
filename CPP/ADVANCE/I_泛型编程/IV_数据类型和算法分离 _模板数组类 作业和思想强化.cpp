#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-08 14 : 05 
//Author : null
//数据类型和算法分离 _模板数组类 作业和思想强化

class Teacher
{
public:
	Teacher()
	{
		age = 33;
		m_p = new char[1];

		strcpy(m_p,"");
	}

	Teacher(char *name ,int age)
	{
		this->age = age;
		m_p = new char[strlen(name) + 1];

		strcpy(m_p,name);
	}

	Teacher(const Teacher & obj)
	{
		m_p = new char[strlen(obj.m_p) + 1];
		strcpy(m_p,obj.m_p);
	}

	~Teacher()
	{
		if(m_p != NULL)
		{
			delete [] m_p;
			m_p = NULL;
		}
	}

	void printT()
	{
		cout<<m_p<<", "<<age<<endl;
	}
protected:
private:
	int age;
	//char name[32];
	//char *pName;
	char *m_p;
public:
	friend ostream & aoperator<<(operator& out,Teacher &t);

	Teacher & operator = (const Teacher& obj)
	{
		//1、
		if(m_p != NULL)
		{
			delete [] m_p;
			m_p = NULL;
			age = 33;
		}
		//2、
		m_p = new char[strlen(obj.m_p) + 1];
		age= obj.age;

		//3、
		strcpy(m_p,obj.m_p);

		return *this;
	}

};

ostream & operator<<(operator& out,Teacher &t)
{
	cout<<t.m_p << ", "<<t.age<<endl;
	return out;
}
void main()
{
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}