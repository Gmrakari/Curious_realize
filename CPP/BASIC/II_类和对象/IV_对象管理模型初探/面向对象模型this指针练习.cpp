#include "iostream"
using namespace std;

//date:2018-09-04 16：31
//Author : null
//面向对象模型 this 指针练习

class Test
{
public:
	Test(int a,int b) //---->Test(Test *this,int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	void prinT()
	{
		cout<<"a"<<a<<endl;
		cout<<"b"<<this->b<<endl;
	}

protected:
private:
	int a;
	int b;
}
void main()
{
	Test t1(1,2);
	t1.prinT(); //====>prinT(&t1);
	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
