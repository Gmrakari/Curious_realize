#include "iostream"
using namespace std;

//date:2018-09-04 14：58
//Author : null
//new 和 delete基础语法 

//1、malloc 和 free
//	new 和 delete 操作符 cpp语法
//2、 new 基础类型变量 分配数组变量 分配对象

//3、
//分配基础类型
void main()
{
	//
	int *a = (int *)malloc(sizeof(int));
	*p = 10;
	free(p);

	int *p2 = new int;//分配基础类型
	*p2 = 20;
	free(p2);

	//
	int *p3 = new int(30);
	printf("*p3:%d\n",*p3);
	delete p3;

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}

//分配数组变量
void main()
{
	//c中分配数组
	int *p = (int *)malloc(sizeof(int )* 10);
	p[0] = 1;
	free(p);

	//cpp分配数组
	
	int *pArray = new int[10];
	pArray[1] = 2;

	delete [] pArray;//数组不要把[] 忘记

	cout<<"helloc"<<endl;
	system("pause");
	return ;
}

//分配对象
class Test
{
public:
	Test(int _a)
	{
		a = _a;
	}
	~Test()
	{
		cout<<"析构函数执行"<<endl;
	}
protected:
private:
	int a;
};


//分配对象new delete 
//相同和不同的地方
//new 能执行类的构造函数 delete操作符能执行类的析构函数
void main()
{
	//c
	Test *pT1 = (Test *)malloc(sizeof(Test));
	free(pT1);

	//cpp
	Test *pT2 = new Test(10);
	delete pT2;

	cout<<"helloc"<<endl;
	system("pause");
	return ;

}