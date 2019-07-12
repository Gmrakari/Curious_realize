#define  _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;

#include "string"
#include <vector>
#include <list>
#include "set"
#include <algorithm>
#include "functional"
#include "iterator"  //输出流迭代器的头文件

//date:2019-07-06 13:00
//Author : null
//Project:_stl算法_for_each和transform算法比较_transform算法源码追踪

void showElem(int &n)
{
	cout<<n<<" ";
}

//一般情况下 for_each 所使用的函数对象，参数是引用，没有返回值

//transform 所使用的参数对象，参数一般不使用引用，而是还有返回值

int showElem2(int n)
{
	cout << n << " ";
	return n;
}

void main43_transform_pk_foreach()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2 = v1;

	for_each(v1.begin(),v1.end(),showElem);

//transform 函数调用的要求	
	/*
c:\program files (x86)\microsoft visual studio 12.0\vc\include\algorithm(988)
	参见对正在编译的函数 模板 实例化
		“_OutIt std::_Transform1<int*,_OutIt,
		void(__cdecl *)(int &)>(_InIt,_InIt,_OutIt,_Fn1,
		std::tr1::true_type)”的引用
1>          with
1>          [
1>              _OutIt=std::_Vector_iterator<std::_Vector_val<int,std::allocator<int>>>,
1>              _InIt=int *,
1>              _Fn1=void (__cdecl *)(int &)
1>          ]
	*/

/*
	template<class _InIt,
	class _OutIt,
	class _Fn1> inline
		_OutIt _Transform(_InIt _First, _InIt _Last,
		_OutIt _Dest, _Fn1 _Func)
	{	// transform [_First, _Last) with _Func
		for (; _First != _Last; ++_First, ++_Dest)
			*_Dest = _Func(*_First);  //解释了 为什么 要有返回值
		return (_Dest);
	}
	*/

	transform(v2.begin(),v2.end(),v2.begin(),showElem2);

}



int main()
{
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}