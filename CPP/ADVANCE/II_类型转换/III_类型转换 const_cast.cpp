#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-08 16 : 21 
//Author : null
//类型转换 const_cast

/*
C风格的强制类型转换(Type Cast)很简单，不管什么类型的转换统统是：
TYPE b = (TYPE)a   

C++风格的类型转换提供了4种类型转换操作符来应对不同场合的应用。
　　　　	static_cast			静态类型转换。如int转换成char
		reinterpreter_cast	重新解释类型 
　　		dynamic_cast		命名上理解是动态类型转换。如子类和父类之间的多态类型转换。
		const_cast			字面上理解就是去const属性。
4种类型转换的格式：
	TYPE B = static_cast<TYPE> (a)
 */  

//const char *p 的const 修饰 让p指向的内存空间 变成只读属性
void printBuf(const char *p)
{
	//p[0] = 'Z';
	char *p1 = NULL;
	//程序员 要清楚的知道 变量:转换之前是什么类型，转换之后 是什么类型
	//const char * ===>char *  //把只读属性 去掉
	p1 = const_cast<char *>(p);

	p1[0] = 'Z'; //通过p1 去修改了内存空间
	cout<<p <<endl;
}

int main()
{
	char buf[] = " aaaaaffffdddd";

	char *myp = " aaaaadddfff";

	//程序员 要确保 p所指向的内存空间 确实能修改 如果不能修改会带来灾难性后果
	printBuf(buf);

	printBuf(myp);

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}