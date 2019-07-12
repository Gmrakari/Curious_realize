#include "iostream"
using namespace std;

//cpp中const的符号表机制的研究和实现
struct Teacher
{
	char name[64];
	int age;
};

//指针所指向的内存空间，不能被修改
int OperatorTeacher(const Teacher *pT)
{
	//可以读
	pT->age = 10;
	return 0;
}


void main02()
{
	const int a;
	int const b;//这两种定义是一样的

	const int *c;
	int * const d;
	const int * const e;
	cout<<"helloc"<<endl;
	system("pause");
}


//C语言中的const是一个冒牌货
//C++语言中的const 是一个真正的常量
//2原因分析
int main()
{
	const int a = 10;
	int *p = NULL;
	p = (int *)&a;

	*p = 20;//间接赋值

	//C++ 把const 的 变量放到一个符号表中。 用的时候才把表里的内容拿出来用
	cout<<a<<endl;

	cout<<*p<<endl;
	return 0;

}
// const分配内存的时机，编译器编译期间
// 

void main()
{
	int a;
	const int b = 10;
	int c;

	printf("&a:%d,&b:%d,&c:%d\n",&a,&b,&c);

	return 0;
}

//4 const 和 #define 的相同之处
//#define 在编译预处理阶段 处理
//5、const 常量是由编译器处理的，提高类型检查和作用域检查
#define d = 20;
void main()
{
	int a = 10;
	int b = 20;
	int array[a+b];//linux 内核里面是成立的;原因是 编译Linux 内核的gcc编译器支持
					//C和Cpp编译器 不支持这种语法现象
	const int c = 10;
	//const int d = 20;

	int array2[c+d];



}

void fun1()
{
	#define a = 10;
	const int b = 20;
	//#undef 

}