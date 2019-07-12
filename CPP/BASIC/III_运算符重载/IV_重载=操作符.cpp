#include "iostream"
using namespace std;

//date:2018-10-03 14:06
//Author : null
//重载=操作符

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
	
	//obj3 = obj1;// c++编译器提供的 等号操作 也属 浅拷贝
	//obj3.operator=(obj1);
	//等号运算符重载
	void operator=(Name &obj1)
	{
		//先把旧的内存释放
		if(this->m_p != NULL)
		{
			delete[] m_p;
			m_len = 0;
		}
		//2 根据obj1 分配内存大小
		this->m_p = obj1.m_len;
		this->m_p = new char [m_len + 1];

		//把obj1赋值
		strcpy(m_p,obj1.m_p);
		return *this;
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

	//Name obj2 = obj1; //c++编译器提供 默认的copy构造函数 浅拷贝

	Name obj3("boj3");

	obj3 = obj1;// c++编译器提供的 等号操作 也属 浅拷贝
	//obj3.operator=(obj1);

/*	operator=(Name &obj1)*/

	//不支持链式编程
	/*obj1 = obj2 = obj3;
	obj2.operator = (obj3);//函数返回的结果为void
	obj1 = void;*/

}
//结论：
//1、先释放旧内存
//2、返回一个引用

void main()
{
	objplaymain();

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}


