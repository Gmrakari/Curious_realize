#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2019-06-27 09:26
//Author : null
//Project:vector基本操作_对象创建_头部尾部操作元素_数组方式遍历

//数组元素的 添加和删除
void main31()
{
	vector<int> v1;

	cout << "length:" << v1.size() <<endl;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	cout << "length:" << v1.size() <<endl;

	cout << "头部元素" << v1.front() << endl;


	//修改 头部元素
	//函数返回值当左值 应该返回一个引用
	v1.front() = 11;
	v1.back() = 55;

	while (v1.size() > 0)
	{
		cout <<"尾部元素" << v1.back() ; //获取尾部元素
		v1.pop_back(); //删除尾部元素
	}
}

//vector的初始化
void main32()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2 = v1;  //对象初始化

	vector<int> v3(v1.begin(), v1.begin()+2 );
}

void printV(vector<int> &v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

//vector的遍历 通过数组的方式 
void main33()
{
	vector<int> v1(10);   //提前把内存准备好

	for (int i=0; i<10; i++)
	{
		v1[i] = i + 1;
	}

// 	for (int i=0; i<10; i++)
// 	{
// 		printf("%d ", v1[i]);
// 	}

	printV(v1);

}

//push_back的强化记忆
void main34() 
{
	vector<int> v1(10);   //提前把内存准备好
	v1.push_back(100);
	v1.push_back(200);
	cout << "size: " << v1.size() << endl;
	printV(v1);
}



void main()
{
	//main31();
	//main32();
	//main33();
	//main34();
	//main35();
	main36();
	cout<<"hello..."<<endl;
	system("pause");
	return ;
}
	