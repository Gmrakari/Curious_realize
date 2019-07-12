#include "iostream"
using namespace std;

//date:2018-09-04 10:18
//Author : null
//深拷贝和浅拷贝


//构造函数是cpp中用于初始化对象状态的特殊函数
//构造函数在对象创建时被自动被调用
//构造函数和普通函数都遵循

class Name
{
public:
	Name(const char *myp)
	{
		int m_len = strlen(myp);
		my =(char *)malloc(m_len + 1);//斜杠/0
		strcpy(m_p,myp);
	}
	//Name obj2 = obj1
	//解决方案 ：手工的编写拷贝构造函数 使用深copy
	Name(const Name& obj1)
	{
		int m_len = obj1.m_len;
		m_p = (char *)malloc(m_len + 1)
		strcpy(m_p,obj1.m_p);
	}
	~Name()
	{
		if(p!=NULL)
		{
			free(p);
			m_p = NULL;
			m_len = 0;
		}
	}
protected:
private:
	char *m_p;
	int m_len;
}

//对象的析构的时候 出现coredump
void objplaymain()
{
	Name obj1("abcdefg");

	Name obj2 = obj1;

	Name obj3("boj3");

	boj3 = boj1;//等号操作

}

void main()
{
	objplaymain();

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
