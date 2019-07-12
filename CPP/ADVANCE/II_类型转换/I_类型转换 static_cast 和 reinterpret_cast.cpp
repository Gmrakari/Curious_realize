#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-08 15 : 05 
//Author : null
//类型转换 static_cast 和 reinterpret_cast 

/*
C风格的强制类型转换(Type Cast)很简单，不管什么类型的转换统统是：
TYPE b = (TYPE)a   

C++风格的类型转换提供了4种类型转换操作符来应对不同场合的应用。
　　　　	static_cast			静态类型转换。如int转换成char
		reinterpreter_cast	重新解释类型 
　　		dynamic_cast		命名上理解是动态类型转换。如子类和父类之间的多态类型转换。
		const_cast，			字面上理解就是去const属性。
4种类型转换的格式：
	TYPE B = static_cast<TYPE> (a)
 */  


int main()
{
	double dpi = 3.14156265354;

	int num1 = (int)dpi;//C类型转换

	int num2 = static_cast<int>(dpi); //静态类型转换 #编译的时c++编译器会做类型检查

	int num3 = dpi; // c语言中 隐式类型转换的地方 均可使用 static_cast<>() 进行类型转换

	// char * ===> int *
	char *p1 = "hello..itcast";

	int *p2 = NULL;

	//p2 = static_cast<int *>(p1); //使用static_cast 编译器编译时，会做类型检查 若有错误，提示错误

	p2 = reinterpret_cast<int *>(p1);

	cout<<"p1："<<p1<< endl;
	cout<<"p2："<<p2 << endl;

	//总结 : 通过static_cast和static_cast 把c 语言的强制类型转化都覆盖了


	cout<<"hellc"<<endl;

	return 0;
}