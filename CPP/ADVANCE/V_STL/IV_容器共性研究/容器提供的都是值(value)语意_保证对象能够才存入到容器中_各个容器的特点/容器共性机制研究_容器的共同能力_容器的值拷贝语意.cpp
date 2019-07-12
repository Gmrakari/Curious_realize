#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "vector"
//date:2019-07-02 17:58
//Author : null
//Project:容器共性机制研究_容器的共同能力_容器的值(value)拷贝语意

/*
1、容器中缓存了 用户的结点
2、结点的类，要保证结点能够插入到容器中
一般结点类，需要提供
	无参构造函数
	拷贝构造函数
	重载=操作符
 */

/*理论提高:所有容器提供的都是值(value)语意，而非引用(reference)语意。容器执行插入元素的操作时，内部实施拷贝动作。
所以STL容器内存储的元素必须能够被拷贝（必须提供拷贝构造函数）*/

class Teacher
{
public:
	Teacher(char name,int age)
	{
		m_pname = new char[strlen(name) + 1];
		strcpy(m_pname,name);
		m_age = age;
	}
	~Teacher()
	{
		if(m_pname != NULL)
		{
			delete[] = m_pname;
			m_pname = NULL;
			m_age = 0;
		}
	}
	//Teacher t2 = t1;
	Teacher(const Teacher &obj)
	{
		m_panme = new char[strlen(obj.m_pname) + 1];
		strcpy(m_pname,obj.m_pname);
		m_age = obj.m_age;
	}

	//重载=号操作符
	// t3 = t2 = t1 
	Teacher& operator=(const Teacher &obj)
	{
		//先把t2的旧内存释放掉
		if(m_pname != NULL)
		{
			delete[] m_pname;
			m_pname = NULL;
			m_age = 0;
		}
		//根据t1的大小分配内存
		m_pname = new char[strlen(obj.m_pname)+1];

		//copy t1的数据
		strcpy(m_pname,obj.m_pname);
		m_age = obj.m_age;
		return *this;
		
	}
	void printT()
	{
		cout<<m_pname<<"\t"<<m_age<<endl;
	}
protected:
private:
	char *m_name;
	int m_age;
};

void main1301()
{
	Teacher t1("t1",31);

	vector<Teacher> v1;
	v1.push_back(t1);//把t1拷贝了一份 存入到容器中了
}

void main()
{
	main1301();
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}