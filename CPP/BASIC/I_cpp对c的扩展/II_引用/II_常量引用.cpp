//Date:2018-08-28
//Author:gm_zzy
//常量引用
#include "iostream"
using namespace std;

void main()
{
	
	//普通引用
	int a = 10;
	int &b = a;
	printf("b:%d\n",b);

	//常引用
	int x = 20;
	const int &y = x;//常引用 是让变量引用只读属性 不能通过y修改x
	//y = 21;

	//常引用初始化 分为2种情况
	//1、用变量初始化 常引用
	{
		int x1 = 30;
		const int &y1 = x;//用x1变量去初始化 常引用
	}
	//2、用字面量 去初始化 常量引用
	{
		const int a = 40;//cpp编译器 把a放在符号表中
		int &m = 41; //普通引用 引用一个字面量 字面量没有内存地址
		//引用就是给内存去多个门牌号（多个别名）'
		
		const int &m = 43;//cpp编译器 会分配内存空间 

	}

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}


//在被调用函数  获取资源
// int PrintTeahcer(const Teacher * const myt)
int PrintTeacher(const Teacher &myt)
{
	//常引用 让实参变量 拥有只读属性
	printf("myt.age :%d\n",myt.age);

}