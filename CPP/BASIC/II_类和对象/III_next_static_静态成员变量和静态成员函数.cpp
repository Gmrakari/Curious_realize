#include "iostream"
using namespace std;

//date:2018-09-04 14：58
//Author : null
//static关键字

class BB
{
public:
	int printC()
	{
		cou<<"c"<<c<<endl;
		return c;
	}
	int AddC()
	{
		c = c + 1;
	}
	static void getC()//静态成员函数
	{
		cou<<"c"<<c<<endl;
		//再静态成员函数中 ，能调用 普通成员属性 或者 普通成员函数吗
		cout<<"a:"<<a<<endl;//error C2597 : 对非静态成员 BB::a 非法引用
	}
protected:
private:
	int a;
	int b;
	static int c;//静态成员变量
};

//静态函数中 不能使用 普通成员变量 普通成员函数 ..
int BB::c = 10;

void main()
{
	BB b1,b2,b3;

	b1.printC();//10

	b2.Addc();//11

	b3.printC();//11

	//静态成员函数的调用方法
	b3.getC();//用对象
	BB::getC()//类::

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
