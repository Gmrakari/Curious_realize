#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "set"
#include "algorithm"
#include "functional"

//date:2019-07-03 13：05 
//Author : null
//Project: stl算法设计理念_函数对象和函数对象当参数和返回值

//函数对象和谓词

//函数对象 类重载了()

template <typename T>
class 
{
public:
	void operator()(T &t)
	{
		n++;
		//
		cout<<t<<" ";
	}
	void printN()
	{
		cout<<"n"<<n<<endl;
	}
protected:
private:
	int n;
};

//函数模板 ==函数
template <typename T>
void FuncShowElemt(T &t)
{
	cout<<t<<endl;
}

//普通函数
void FuncShowElemt2(int &t)
{
	cout<<t<<endl;
}

//函数对象 定义
//函数对象和普通函数的区别
void main01()
{
	int a = 10;
	ShowElemt<int> showElemt;
	showElemt(a);//函数对象的()的执行 很像一个函数 //仿函数

	FuncShowElemt<int>(a);
	FuncShowElemt2(a);
}

//函数对象是属于类对象，能突破函数的概念，能保持调用状态信息
//函数对象的好处
//for_each算法中 函数对象做函数参数
//for_each算法中 函数对象当返回值
void main02()
{
	vector<int> v1;
	c1.push_back(1);
	c1.push_back(3);
	c1.push_back(5);

	for_each(v1.begin(),v1.end(),ShowElemt<int>());//匿名函数对象 匿名仿函数
	cout<<endl;
	for_each(v1.begin(),v1.end(),FuncShowElemt2(2));//通过回调函数 谁使用for_each 谁去填写回调函数的入口地址


	ShowElemt<int> show1;
	//函数对象 做函数参数
	//
	

	// 1 for_each算法的 函数对象的传递 是元素值传递 不是引用传递
	for_each(v1.begin(),v1.end(),show1);
	show1.printN();

	cout<<"通过for_each算法的返回值看调用的次数"<<endl;
	show1 = for_each(v1.begin(),v1.end(),show1);
	show1.printN();

	// 结论 要点 ： 分清楚 stl算法返回的值是迭代器 还是 谓词（函数对象）
	// 这个是stl算法入门的重要点

void main()
{
	
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}