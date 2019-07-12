
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

class Test
{
public:
	Test()  //无参数 构造函数
	{
		a = 10;  //作用完成对属性的初始化工作
		p = (char *)malloc(100);
		strcpy(p, "aaaaffff");
		cout<<"我是构造函数 被执行了"<<endl;
	}
	void print()
	{
		cout<<p<<endl;
		cout<<a<<endl;
	}
	~Test() //析构函数
	{
		if (p != NULL)
		{
			free(p);
		}
		cout<<"我是析构函数,被调用了" <<endl;
	}
protected:
private:
	int a ;
	char *p;
};

//给对象搭建一个舞台,研究对象的行为
void objplay()
{
	//先创建的对象 后释放
	Test t1;
	t1.print();

	printf("分隔符\n");
	Test t2;
	t2.print();
}
void main11()
{
	objplay();
	cout<<"hello..."<<endl;
	system("pause");
	return ;
}