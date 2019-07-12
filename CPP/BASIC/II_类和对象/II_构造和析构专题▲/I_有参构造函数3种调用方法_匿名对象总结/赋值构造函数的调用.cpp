#include "iostream"
using namespace std;

//date:2018-09-02 09:42
//Author : null
//赋值构造函数的调用

class Test4
{
public:
	Test4()//无参数构造函数
	{
		m_a = 0;
		m_b = 0;
		cout<<"无参数构造函数"<<endl;
	}
	Test4(int a,int b)//有函数构造函数
	{
		m_a = a;
		m_b = b;
		cout<<"有参数构造函数"<<endl;
	}
	//复制构造函数（copy 构造函数)
	Test4(const Test2 & obj)
	{
		cout<<"我也是构造函数"<<endl;
		m_b = obj.m_b+100;
		m_a = obj.m_a+100;//这个有什么作用？
	}
public:
	void printT()
	{
		cout<<"普通函数"<<endl;
		cout<<"m_a"<<m_a<<"m_b_b"<<m_b<<endl;
	}
private:
	int m_a;
	int m_b;
}

void main()
{
	Test4 t1(1,2);
	Test4 t0(1,2);

	t0 = t1;//用t1给t0赋值 等号操作 和初始化 是两个不同的概念

	//第一种调用方法
	Test4 t2 = t1;//用t1 来初始化 t2
	t2.printT();


	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
//第二种调用时机
void main()
{
	Test4 t1(1,2);
	Test4 t0(1,2);

	Test4 t2(t1);
	t2.printT();
}