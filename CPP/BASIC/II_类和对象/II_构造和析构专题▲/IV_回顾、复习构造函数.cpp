#include "iostream"
using namespace std;

//date:2018-09-02 11:57
//Author : null
//回顾、复习构造函数

class Test
{
public:
	Test()
	{
		cout<<"无参数构造函数 自动被调用"<<endl;
	}
	void printT()
	{
		cout<<"a:"<<a<<"b"<<b<<endl;
	}
	Test(int _a)
	{
		a = _a;
		b = 0;
	}
	Test(const Test &obj)//构造一个copy 用一个对象初始化另外一个对象。
	{
		a = obj.a+100;
		b = boj,b  + 100;

	}
	~Test()
	{
		<<"我是析构函数 对象声明周期结束时 会被cpp编译器自动调用"<<endl;
	}
protected:
private:
	int a;
	int b;
};


//返回一个元素,匿名对象
Test getTestObj()
{
	Test t(1);
	return t;
}

void TestNoNameObj()
{
	Test myt1 = getTestObj();//用匿名对象初始化 另外一个对象
	Test myt2(1);
	myt2 = getTestObj(); //用匿名对象 给 另外一个对象 赋值 匿名对象被析构
}

//第三种调用时机

void printTest(Test t)
{

}

//1和2
void objplaymain2()
{
	Test t1(1);//ok

	Test t2(t1);

	Test t3 = t1;//会调用copy构造函数

	printTest(t3);
}

void main()
{
	Test t1;
	Test t2();//调用无参数构造函数 的错误用法

	t2.printT();

	Test t3(1);//cpp编译器自动的调用构造函数

	Test t4 = 4;//cpp编译器自动的调用构造函数

	Test t5 = Test(5);//程序员手工的调用构造函数

	Test t6 = t1;
	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}


void main()
{
	TestNoNameObj();

}