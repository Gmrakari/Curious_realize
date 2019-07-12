//Date:2018-08-28
//Author:gm_zzy
//函数重载(Overroad)
#include "iostream"
using namespace std;

void myPrint(int a)
{
	printf("a:%d\n",a);
}

void myPrint(char *p)
{
	printf("%s\n", p);
}

void myPrint(int a,int b)
{
	printf("a:%d\n",a);
	printf("b:%d\n",b);
}

//1、当函数名和不同的参数搭配时 函数的含义不同
//2、函数从在的判断标准
//3、名称 参数 返回值
//名称相同 参数不一样（个数/类型）
//返回值 不是 判断函数重载的标准
void main()
{
	
	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}


