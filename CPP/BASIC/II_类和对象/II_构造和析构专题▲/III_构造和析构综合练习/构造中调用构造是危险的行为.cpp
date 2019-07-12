#include "iostream"
using namespace std;

//date:2018-09-04 14:36
//Author : null
//构造中调用构造函数

//构造中调用构造是危险的行为
class MyTest
{
public:
	MyTest(int a,int b,int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	MyTest(int a,int b)
	{
		this->a = a;
		this->b = b;

		MyTest(a,b,100);

	}
	~MyTest()
	{
		printf("MyTest~:%d, %d, %d \n",a,b,c);
	}
protected:
private:
	int a;
	int b;
	int c;
public:
	int getC() const
	{
		return c;
	}
	void setC(int val)
	{
		c = val;
	}
};


void main()
{
	MyTest t1(1,2);
	printf("c:%d",t1.getC());//c的值为多少?

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
