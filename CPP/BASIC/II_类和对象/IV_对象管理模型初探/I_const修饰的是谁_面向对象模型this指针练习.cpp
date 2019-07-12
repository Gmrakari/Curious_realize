#include "iostream"
using namespace std;

//date:2018-09-07 18:47
//Author : null
//const修饰的是谁

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
	//1、const写在这两个地方都没有任何关系,why ?
	//2、const 修饰的是谁？
	//	2-1const修饰的是形参a
	//	2-2const 修饰的是属性this->a? this->b?
	//	2-3const修饰的是this指针指向的内存空间，修饰的是this指针
	const void OpVar(int a,int b)  /*const*/  //一般写在后面
	{					//==>void OpVar(const Test *this,int a,int b) const 所指向的内存空间，所以都不能修改
		a = 100;
		/*cout<<"a"<<a<<endl;*/
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
