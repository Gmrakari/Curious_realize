#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "map"
#include "string"

//date:2019-07-02 16:21
//Author : null
//Project:map容器基本操作_查找和查找的异常处理

void main1103()
{
	map<int, string> map1;

	//方法1
	map1.insert(pair<int, string>(1,"teacher01") );
	map1.insert(pair<int, string>(2,"teacher02") );

	//方法2 
	map1.insert(make_pair(3, "teacher04") );
	map1.insert(make_pair(4, "teacher05") );

	//方法3 
	map1.insert(map<int, string>::value_type(5, "teacher05") );
	map1.insert(map<int, string>::value_type(6, "teacher06") );

	//方法4
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	//容器的遍历
	for (map<int, string>::iterator it = map1.begin(); it!=map1.end(); it++ )
	{
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "遍历结束" << endl;

	//map的查找 //异常处理
	map<int, string>::iterator it2 = map1.find(100);
	if (it2 == map1.end())
	{
		cout << "key 100 的值 不存在" << endl;
	}
	else
	{
		cout << it2->first << "\t" << it2->second << endl;
	}

	//equal_range //异常处理
	pair<map<int, string>::iterator , map<int, string>::iterator> mypair = map1.equal_range(5); //返回两个迭代器 形成一个 pair
	//第一个迭代器 >= 5的 位置 
	//第二个迭代器 = 5的 位置 

	if (mypair.first == map1.end() )
	{
		cout << "第一个迭代器 >= 5的 位置 不存在" << endl;
	}
	else
	{
		cout << mypair.first->first << "\t" << mypair.first->second << endl;
	}

	//使用第二个迭代器
	if (mypair.second == map1.end() )
	{
		cout << "第二个迭代器 > 5的 位置 不存在" << endl;
	}
	else
	{
		cout << mypair.second->first << "\t" << mypair.second->second << endl;
	}


}


void main()
{
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}