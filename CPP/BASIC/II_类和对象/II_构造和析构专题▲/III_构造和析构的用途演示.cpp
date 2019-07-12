#include "iostream"
using namespace std;

//date:2018-09-01 16:32 
//Author : null
//构造和析构的用途演示

class Test
{
public:
	Test() // 无参数 构造函数
	{
		a = 10;
		p = (char *)malloc(100);
		strcpy(p,"aaaafff");
		cout<<"我是构造函数,被执行了"<<endl;
	}
	void print()
	{
		cout<<p<<endl;
		count<<a<<endl;
	}
	~Test()
	{
		if(p!=NULL)
		{
			free(p);
		}
		cout<<"我是析构函数，被调用了"<<endl;
	}
protected:
private:
	int a;
	char *p;
};

//给对象搭建一个舞台，研究对象的行为
void objplay()
{
	//先创建的对象，后释放
	Test t1;
	t1.print();

	printf("分隔符");

	Test t2;
	t2.print();
}

int main()
{
	Test t1,t2;

	objplay();

	cout<<"helloc"<<endl;

	return 0;
}
