#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "vector"
//date:2019-07-03 14:44
//Author : null
//Project: stl算法设计理念 一元函数对象和一元谓词
// 一元谓词 函数参数一个
// 

template<typename T>
class IsDiv
{
public:
	IsDiv(const T &divisor)
	{
		this->divisor = div;
	}
	bool operator()(T &t)
	{
		return (t%divisor == 0);
	}
protected:
private:
	T divisor;
};


void main03()
{
	vector<int> v2;
	for(int i = 10;i < 33;i++)
	{
		v2.push_back(i);
	}
	int a = 4;
	IsDiv<int> myDiv(a);

	//方法一
	find_if(v2.begin(),v2.end(),myDiv);
/*
	template<class _InIt,class _Pr> inline
	_InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{		// find first satisfying _Pred
		_DEBUG_RANGE(_First, _Last);
		_DEBUG_POINTER(_Pred);
		return (_Rechecked(_First,_Find_if(_Unchecked(_First), _Unchecked(_Last), _Pred)));
	}
	//find_if返回值是一个迭代器
	//要点：分清楚 stl算法返回的值是迭代器 还是谓词（函数对象） 是stl算法入门的重要点
*/
	//方法二
	vector<int>::iterator it;
	it = find_if(v2.begin(),v2.end(),myDiv<int>(4));
	if(it == v2.end())
	{
		cout<<"容器中没有被4整出的元素"<<endl;
	}
	else
	{
		cout<<"第一个是被4整除的元素是"<<*it<<endl;
	}
	
}


void main()
{
	main03();//一元谓词
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}