#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include <list>
#include <algorithm>
#include "functional"
#include <vector>
#include "set"

//date:2019-07-06 09：32
//Author : null
//Project:stl算法设计理念_预定义函数对象和函数适配器

//plus<int> 预定好的函数对象，能实现不同类型的数据的+运算
//实现了 数据类型 和算法 的分类 ===> 通过函数对象技术实现的

//思考:怎么知道 plus<type> 是两个参数 
void main21()
{
	/*
	template<class _ty>
	struct plus:public binary_function<_Ty,_Ty,_Ty>
	{
		//functor for operator+
		_TY operator()(const _Ty& _Left,const _Ty& _Right) const
		{
			//apply operator+ to operands
			return (_Left + _Right);
		}
	}
	*/

	plus<int> intAdd;
	int x = 10;
	int y = 20;
	int z = intAdd(x,y);//equal x plus y 
	cout<<"z:"<<z<<endl;


	plus<string> stringAdd;
	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = stringAdd(s1,s2);
	cout<<"s3: "<<s3<<endl;

	vector<string> v1;
	v1.push_back("bbb");
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("zzz");
	v1.push_back("ccc");
	v1.push_back("ccc");
	v1.push_back("ccc");
	/*
	template<class _Ty>
	struct greater:public binary_function<_Ty,_Ty,_Ty>
	{
		//functor for operator+
		_TY operator()(const _Ty& _Left,const _Ty& _Right) const
		{
			//apply operator+ to operands
			return (_Left + _Right);
		}
	}
	*/	

	sort(v1.begin(),v1.end(),greater<string>());

	for(vector<string>::iterator it = v1.begin();it != v1.end();it++)
	{
		cout<<*it<<endl;
	}

	//求ccc出现的个数
	string sc = "ccc";

	//equal_to<string>() 有两个参数 left参数来自容器 ,right参数来自sc
	//bind2nd 函数适配器 作用:把预定义函数对象 和 第二个参数 进行绑定
	int num = count_if(v1.begin(),v1.end(),bind2nd( equal_to<string>(),sc));
	cout<<"num: "<<num<<endl;
}	

int main()
{
	main21();

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}