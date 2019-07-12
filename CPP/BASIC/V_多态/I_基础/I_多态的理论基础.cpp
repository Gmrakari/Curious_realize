#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-28 16:25
//Author : null 
//多态的理论基础
//


/*静态联编和动态联编
1、联编是指一个程序模块、代码之间互相关联的过程
2、静态联编(static bindling),是程序的匹配、连接在编译阶段实现，也称为早期匹配。
重载函数使用静态联编
3、动态联编是指程序联编推迟到运行时进行，所以又称为晚期联编(迟绑定)
switch语句和if语句时动态联编的例子
4、理论联系实际
(1、)cpp和c相同，是静态编译型语言
(2、)在编译时，编译器自动根据指针的类型判断指向的一个什么样的对象；所以编译器认为父类指针指向的是父类对象
(3、)由于程序没有运行，所以不可能知道父类指针指向的具体是父类对象还是子类对象，从程序安全的
角度，编译器架设父类指针指向父类对象，因此编译的结果为调用父类的成员函数。这种特性就是静态联编。*/
class HeroFighter
{
public:
	virtual int power()
	{
		return 10;
	}
};
void PlayObj(HeroFighter *hf,EnemFighter *ef)
{
	//不写virtual 关键字 是静态联编 cpp编译器根据HeroFighter 类型，去执行 这个类型的power函数
	//动态联编：迟绑定：//在运行的时候，根据具体对象（具体的类型)，执行不同对象的函数，表现成多态
	if(hf->power() > ef.attack())//hf->power() 函数调用会有多态发生
	{
		cout<<"主角win"<<endl;
	}
	else
	{
		cout<<"主角挂了"<<endl;
	}
}

void main()
{
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	