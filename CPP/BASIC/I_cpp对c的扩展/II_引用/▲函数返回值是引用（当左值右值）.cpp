#include "iostream"
using namespace std;
//函数返回值是引用（当左值右值）
/*当函数返回值为引用时
若返回栈变量
不能成为其它引用的初始值
不能作为左值使用*/

int getAA()
{
	int a;
	a = 10;
	return a;
}

int & getAA2()
{
	int a ;
	a = 10;
	return a;
}

int * getAA3()
{
	int a;
	a = 10;
	return &a;
}

//
//若返回静态变量或全局变量
//可以成为其它引用的初始值
//即可作为右值使用，可可以作为左值使用
int j1()
{
	static int a = 10;
	a++;
	return a;
}

int& j2()
{
	static int a = 10;
	a++;
	return a;
}

int g1()
{
	static int a = 10;
	a++;
	return a;
}

int& g2()
{
	static int a = 10;
	a++;
	printf("a:%d\n", a);
	return a;
}

int main()
{
	int a1 = getAA();

	int a2 = getAA2();

	int &a3 = getAA2();

	a1 = j1();
	a2 = j2();
	int &a3= j2();

	cout<<a1<<endl;
	cout<<a2<<endl;
	cout<<&a3<<endl;

	g2() = 100;
	g2();

	int c1 = g1();
	int c2 = g2();

	cout<<"helloc"<<endl;
	return 0;
}




