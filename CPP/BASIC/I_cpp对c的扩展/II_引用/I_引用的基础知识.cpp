#include "iostream"
using namespace std;

//引用的基础知识
//1、引用的概念
//属于cpp编译器对c的扩展，不能用c语言的思维思考
void main()
{
	int a = 10;
	//引用的语法 Type& name = var;
	int &b = a;

	b = 100//相当于把a修改成了100

	a = 200;

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}

//基础类型的引用
//
int myswap(int a,int b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

int myswap02(int *a,int *b)
{
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

int myswap03(int &a,int *&b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void main(){

	int x,y;
	x = 10;
	y = 20;

	myswap(x,y);
	printf("x:%d,y:%d\n",x,y );

	myswap02(&x,&y);
	printf("x:%d,y:%d\n",x,y );

	myswap03(x,y);
	printf("x:%d,y:%d\n",x,y );

	int a = 10;
	int &b = a;
	int &c;//普通引用 必须要初始化

	return 0

}

