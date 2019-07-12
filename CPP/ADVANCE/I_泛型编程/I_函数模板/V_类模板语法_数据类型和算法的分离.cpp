#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-11-20 22:16
//Author : null
//类模板语法_数据类型和算法的分离
//

/*
	类模板用于实现所需数据的类型参数化
	类模板在表示如数组、表、图等数据结构显得特别重要
	这些数据结构的表示和算法不受所包含的元素类型的·影响
 */

//A编程模板 类
//模板类 类型参数化

//类模板的定义
//类模板的使用
//类模板 做函数
template<typename T>
class A
{
public:
	A(T a = 0)
	{
		this->a = a;
	}
public: 
	void printA()
	{
		cout<<"a:"<<a<<endl;
	}
protected:
private:
	T a;

};

//类模板 做函数参数
//参数 cpp编译器 要求具体的类 所以 要A<int> &a
void UseA(A<int> &a)
{
	a1.printA();
}

void main()
{ 
	//模板类(本身就是类型化) ===具体的类 ===>定义具体的变量
	A<int> a1(11) ,a2(20) , a3(30);/*A a1(11); //模板类是抽象的，===>需要进行 类型具体*/ 

	a1.printA();

	UseA(a1);
	UseA(a2);
	UseA(a3);


	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}