
#include "iostream"
using namespace std;

//date:2018-09-04 16:03
//Author : null
//面向对象模型初探

//cpp中类对象的成员变量和成员函数是分开存储的
//成员变量：
//普通成员变量：存储于对象中，于struct 变量有相同的内存布局和字节对齐方式
//静态成员变量：存储于全局数据区中
//成员函数：存储于代码段中

/*总结：1、cpp类对象中的成员变量和成员函数是分开存储的，C语言的内存四区模型仍有效
2、cpp中的普通成员函数都隐式包含一个指向当前对象的this指针
3、静态成员函数、成员变量属于类
静态成员函数与普通成员函数的区别
静态成员函数不包含指向具体对象的指针
普通成员函数包含一个指向具体对象的指针*/
class Test
{
private:
	int mI;

public:
	Test(int i)
	{
		mI = i;
	}

	int getI()
	{
		return mI;
	}

	static void Print()
	{
		printf("This is class Test\n");
	}
};

Test a(10);

a.getI();

Test::Print();

/*struct Test
{
	int mI;
};

void Test_initialize(Test * PThis,int i)
{
	pThis->mI = i;
}

int Test_getI(Test* pThis)
{
	return pThis->mI;
}

void Test_Print()
{
	printf("This is class Test\n");
}

Test a;
Test_initialize(&a,10);
Test_getI(&a);
Test_Print();
*/


void main()
{
	
	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
