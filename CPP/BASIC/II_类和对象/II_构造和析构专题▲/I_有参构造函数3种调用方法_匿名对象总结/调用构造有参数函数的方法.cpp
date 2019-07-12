#include "iostream"
using namespace std;

//date:2018-09-01 17:27 
//Author : null
//调用有参数函数的方法

class Test2
{
public:
	Test2()//无参数构造函数
	{
		m_a = 0;
		m_b = 0;
		cout<<"无参数构造函数"<<endl;
	}
	Test2(int a,int b)//有函数构造函数
	{
		m_a = a;
		m_b = b;
		cout<<"有参数构造函数"<<endl;
	}
	//复制构造函数（copy 构造函数)
	Test2(const Test2 & obj)
	{
		cout<<"我也是构造函数"<<endl;
	}
public:
	void printT()
	{
		cout<<"普通函数"<<endl;
	}
private:
	int m_a;
	int m_b;
}

//调用有参数函数有三种方法

void main()
{
	Test2 t1;//这样写的话 调用无函数构造函数  cpp自动的调用构造函数
	t1.printT();

	//法一、括号法
	Test2 t1(1,2);//调用有函数构造函数	cpp自动的调用构造函数

	//法二、
	Test2 t2 = (3,4);// = cpp对等号操作符 进行功能性增强

	//法三、直接调用构造函数 手动的调用构造函数
	Test2 t4 = Test2(1,2);//匿名对象 （匿名对象的去和留） 

	cout<<"hell"<<endl;
	system("pause");
	return 0;
}
