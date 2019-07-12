#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "string"
#include "algothorm"
//date:2019-04-01 19：18
//Author : null
//Project:stl的string的典例操作_初始化_遍历_连接_和字符指针转化_查找替换
//

//string 是一个类，char *是一个指向字符的指针
//string封装了char* ，管理这个字符串，是一个char*型的容器


//string 的初始化

void main21()
{
	string s1 = "aaaa";
	string s2("bbbbb");
	string s3 = s2;//通过拷贝构造函数来初始化对象s3

	string s4 = (10,'a');

	cout<<"s1: "<<s1<<endl;
	cout<<"s2: "<<s2<<endl;
	cout<<"s3: "<<s3<<endl;
	cout<<"s4: "<<s4<<endl;

}

//string 的 遍历
//
void main22()
{	
	string s1 = "abcdefg";

	//数组方式
	for(int i = 0;i < s1.lenth();i++)
	{
		cout<<a[i]<<endl;
	}

	//迭代器
	
	for(string::inerator = s1.begin();it != s1.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	try
	{
		for(int i = 0;i < s1.length();i++)
		{
			cout<<s1.at(i)<<" ";//抛出异常
		}		
	}
	catch(...)
	{
		cout<<"发生异常"<<" ";
	}

}

//字符指针和string 的转换

void main23()
{
	string s1 = "aaabbbb";

	// 1 、s1 ===> char *;
	printf("s1:%s\n",s1.c_str());

	// 2、 char * == > string


	// 3、s1的内容 copy到buf中
	char buf1[128] = {0};
	s1.copy(buf,3,0);		//注意 只给你copy3个字符 不会变成c风格的字符串
	cout<<"buf1: "<<buf1<<endl;

}

//string 连接
void main24()
{	
	string s2 = "aaa";
	string s2 = "bbb";

	s1 = s1 + s2;
	cout<<"s1"<<s1<<endl;

	string s3 = "333";
	string s4 = "444";

	s3.append(s4);

	cout<<"s3: "<<s3<<endl;
}

//sting 查找 和 替换
void main25()
{
	string s1 = "wbm hello wbm 111 wbm 222 wbm 333";

	//第一次出现 wbx index;
	int s1.finn("wbm",0);
	cout<<"index: "<<index;endl;

	//案例一、求wbm出现的次数 每一次出现的数组下标
	int offindex = s1.find("wbm",0);

	while(offindex != string::npos)
	{
		cout<<"offindex: "<<offindex<<endl;
		offindex = offindex + 1;
		offindex = s1.find("wbm",offindex);
	}
	//案例二、把小写wbm == > WBM
	
	offindex = s1.find("wbm",0);
	while(offindex != string::npos)
	{
		cout<<"offindex: "<<offindex<<endl;
		s1.replace(offindex,3,"WBM");
			offindex = offindex+ 1;
			offindex = s1.find("wbm",offindex);//
	}

}

//截断（区间删除）和插入

void main26()
{
	string s1 = "hello1 hello2 hello3";
	string::iterator it = find(s1.begin(),s1.end(),'l');
	if(it != s1.end())
	{
		s1.erase(it);
	}
	cout<<"s1删除以后的结果: "<<s1<<endl;

	s1.erase(s1.begin(),s1.end());
	cout<<"s1全部删除:"<<s1<<endl;

	cout<<"s1长度"<<s1.length()<<endl;

	string s2 = "BBB"
	s2.insert(0,"AAA");//头插法

	cout<<"s2: "<<s2<<endl;

	s2.insert(s2.length(),"CCC");//尾插法

	cout<<"s2: "<<s2<<endl;

}

void main27()
{
	string s1 = "AAAbbb";
	//1、函数的入口地址 2、函数对象 3、预定义的函数
	transform(s1.begin(),s1.end(),toupper);//转换
	cout<< "s1: "<< s1 << endl;

	string s2 = "AAAbbb";

	transform(s1.begin(),s1,end(),tolower);

	cout<< "s2: "<<s2 <<endl;

}

void main()
{
	//main21();
	//main22();
	//main23();
	//main24();
	main25();
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	