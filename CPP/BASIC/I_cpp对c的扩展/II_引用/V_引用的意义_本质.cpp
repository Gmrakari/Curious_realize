

#include "iostream"
using namespace std;
//4、引用的意义
//1）引用作为其它变量的别名而存在，因此在一些场合可以代替指针
//2）引用相对于指针来说具有更好的可读性和实用性
void main()
{
	const int c1 = 10;

	int a = 10;
	int &b = a;

	printf("&a:%d\n",&a);
	printf("&b:%d\n",&b);//====>a和b就是同一块内存空间的门牌号
	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}


struct Teacher
{
	char name[64];//64个字节
	int age;//4

	int &a;//4  很像指针 所占的内存空间大小
	int &b;//4  
}
// 3、引用的本质
// 1）引用的实现上，只不过是把：间接赋值成立的三个条件的后两步二合为一
// 2）当我们使用引用语法的时候，我们不去关系编译器引用是怎么做的
// 当我们分析奇怪的语法现象的时候，我们才去考虑cpp编译器是怎么做的

void modefyA(int &a)
{
	a1 = 100;//*
}

void modefyA2(int * const a1)
{
	*a1 = 200;//*实参的地址 去间接的修改实参的值
}

void main()
{
	char *const p;
	int a = 10;
	modefyA(a);//执行这个函数调用的时候，我们不需要去a的地址
	printf("a:%d\n",a);

	modefyA2(&a);//如果是指针，需要我们手工取实参的地址
	printf("a:%d\n",a);	

	printf("sizeof(Teacher):%d\n",sizeof(Teacher));
}

// 1、引用在cpp中的内部实现是一个常指针

//间接赋值
//三个条件 
void modefyA3(int *p)
{
	*p = 200;//第三个条件 *p  
}

void main()
{
	int a = 10;
	int *p = NULL;//条件1 定义两个变量

	p = &a;
	*p = 100;

	{
		*p = 200;
	}

	modefyA3(&a)// 第二个条件 建立关联
} 

//引用的本质：


