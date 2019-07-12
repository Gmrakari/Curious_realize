#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "string"
#include <vector>
#include <list>
#include "set"
#include <algorithm>
#include "functional"
#include "iterator"

//date:2019-07-06 10：58
//Author : null
//Project:stl算法概念和分类 & foreach和transform基本使用

/*

操作对象

	直接改变容器的内容
	将原容器的内容复制一份，修改其副本，然后传回给该副本

功能
	非可变序列算法 指不直接修改其所操作的容器内容的算法

		计数算法 count、count_if
		搜索算法 search、find、find_if、find_first_of、...
		比较算法 equal、mismatch、lexicographical_compare

	可变序列算法 指 可以修改它们所操作的容器内容的算法

		删除算法 remove、remove_if、remove_copy
		修改算法 for_each、transform
		排序算法 sort、stable_sort、partial_sort

	排序算法 包括对序列进行排序和合并的算法、搜索算法以及有序序列上的集合操作

	数值算法 对容器内容进行数值计算

*/

/*

常用算法汇总

常用的查找算法
adjacent_find()[adjacent mean 邻近],binary_search(),count,count_if(),equal_range(),find(),find_if()

常用的排序算法
merge(),sort(),random_shuffle()[shuffle mean 洗牌],reverse()

常用的拷贝和替换算法
copy(),replace(),replace_if(),swap()

常用的算术和生成算法
accumulate()[accumulate mean 求和],fill()

常用的集合算法
set_union(),set_intersection(),set_difference()

常用的遍历算法
for_each(),transform()[transform mean 变换]

*/

/*

foreach:用指定函数依次对指定范围内所有元素进行迭代访问。该函数不得修改序列中的元素

函数定义: For_each(begin,end,func);

template<class _InIt,class _Fn1>
inline _Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
	{	// perform function for each element
	_DEBUG_RANGE(_First, _Last);
	_DEBUG_POINTER(_Func);
	_For_each(_Unchecked(_First), _Unchecked(_Last), _Func);
	return (_STD move(_Func));
	}

*/
void printV(vector<int> &v)
{
	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
}

void printList(list<int> &v)
{
	for(list<int>::iterator it = v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
}

void showElem(int &n)
{
	cout<<n<<" ";
}

class CMyShow
{
public:
	void operator()(int &n)
	{
		num++;
		cout<<n<<" ";
	}
	void printNum()
	{
		cout<<"num:"<<num<<endl;
	}
private:
	int num;
};

void main4_foreach()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV(v1);

	//函数对象 或者 回调函数的入口地址
	for_each(v1.begin(),v1.end(),showElem);
	cout<<endl;

	for_each(v1.begin(),v1.end(),CMyShow());
	cout<<endl;

	CMyShow my1 = for_each(v1.begin(),v1.end(),CMyShow());
	my1.printNum();

	/*
	
	template<class _InIt,
	class _Fn1> inline
	_Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
	{	// perform function for each element
	_DEBUG_RANGE(_First, _Last);
	_DEBUG_POINTER(_Func);
	_For_each(_Unchecked(_First), _Unchecked(_Last), _Func);

	return (_STD move(_Func));
	}

	 */

	CMyShow mya;
	CMyShow my1 = for_each(v1.begin(),v1.end(),mya);//给mya 初始化
	mya.printNum();	//mya 和 my1 是两个不同的对象 结果输出 : ====> Num:0
	my1.printNum();

	my1 = for_each(v1.begin(),v1.end(),mya);//给my1 赋值
	my1.printNum();


}

/*

transform 与 for_each 类似 ,遍历所有元素，但可对容器的元素进行修改
transform()算法右两种形式

	transform(b1,e1,b2,op)
	transform(b1,e1,b2,b3,op)

	template<class _Init,class _Outlt,class _Fn1>inline
	_Outlt transform(_InIt_First,_InIt_Last,_OitIt_Dest,_Fn1_Func)

transform()的作用
例如:可以一个容器的元素，通过op，变换道另一个容器中（同一个容器中）
也可以把两个容器的元素,通过op,变换到另一个容器中


 */

int increase(int i)
{
	return i+100;
}

void main42_transform()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV(v1);	//打印结果 1 3 5
	cout<<endl;

	//使用回调函数
	transform(v1.begin(),v1.end(),v1.begin(),increase);
	printV(v1);	//打印结果 101 103 105 
	cout<<endl;	

	//使用 预定义的函数对象
	transform(v1.begin(),v1.end(),v1.begin(),negate<int>());
	printV(v1);	//打印结果 -101 -103 -105 
	cout<<endl;

	//使用 使用 函数适配器 和 函数对象
	list<int> mylist;
	mylist.resize(v1.size());
	transform(v1.begin(),v1.end(),mylist.begin(),bind2nd(multiplies<int>(),10));
	printList(mylist);	//打印结果 -1010 -1030 -1050 
	cout<<endl;

	//transform 也可以把运算结果  直接输出到屏幕
	transform(v1.begin(),v1.end(),ostream_iterator<int>(cout," "),negate<int>());
	cout<<endl;
	//打印结果 101 103 105 
}

int main()
{
	main41_foreach();
	main42_transform();
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}