#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2019-06-29 11:45
//Author : null
//Project:vector的基本操作_删除和插入(重点)

//vector的删除
void main36()
{
	vector<int> v1(100);
	for(int i = 10;i < 10;i++)
	{
		v1[i] = i + 1;
	}	

	//区间删除
	v1.erase(v1.begin(),v1.begin()+3);

	//根据元素的位置 指定位置删除
	v1.erase(v1.begin()); //在头部删除一个元素

	printV(v1);

	cout<<endl;

	//根据元素的值
	v1[1] = 2;
	v1[3] = 2;

	printV(v1);

	for(vector<int>::iterator it = v1.begin();it != v1.end();)
	{
		if(*it == 2)
		{
			it = v1.erase(it);//当删除迭代器所指向的元素的时候,erase删除函数会让it自动下移动
			//把旧的位置 给 新的位置 
		}
		else
		{
			it ++;
		}
	}
	printV(v1);
	cout<<endl;

	vi.insert(v1.begin(),100);
	vi.insert(v1.end(),200);	

	printV(v1);
	cout<<endl;
}

void printV(vector<int> &v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout << v[i] << " ";
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
	