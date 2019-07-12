#include "iostream"
using namespace std;

//date:2018-09-04 10:12
//Author : null
//构造函数调用规则研究

class Test
{
public:
	Test(const Test &obj)//构造一个copy 用一个对象初始化另外一个对象。
	{
		a = obj.a+100;
		b = boj,b  + 100;
	}

	void printT()
	{
		cout<<"a:"<<a<<"b"<<b<<endl;
	}

protected:
private:
	int a;
	int b;
};

//当类中定义了拷贝构造函数时，cpp编译器不会提供无参数构造函数

//当类中定义了有参数构造函数时，cpp编译器不会提供无参数构造函数

//在定义类时，只要你写了构造函数，则必须要用
void main()
{
	Test t1;//第一种编译失败
	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
