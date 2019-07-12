#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2019-06-29 11:33
//Author : null
//Project:vector的迭代器遍历和迭代器的种类



//迭代器 
//1、 1 3 5
//   ▲    
//   	  ▲
// 当it = v1.end()的时候 说明这个容器已经遍历完毕了...
// end()的位置 应该是5的后面
//
//2、迭代器的种类

/*
typedef iterator pointer;
typedef const_iterator const_pointer;
typedef _STD reverse_iterator<iterator> reverse_iterator;
typedef _STD reverse_iterator<const_iterator> const_reverse_iterator;
*/

void main35()
{
	vector<int > v1(100);

	//正序遍历
	for(int i = 0;i<10;i++)
	{
		v1[i] = i + 1;
	}
	for(vector<int>::iterator it = v1.begin();it != v1.end();it++)
	{
		cout<<*it<<" ";
	}

	//逆序遍历
	for(vector<int>::reverse_iterator rit = v1.rbegin();rit!=v1.rend();rit++)
	{
		cout<<*rit<<" ";
	}
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
	