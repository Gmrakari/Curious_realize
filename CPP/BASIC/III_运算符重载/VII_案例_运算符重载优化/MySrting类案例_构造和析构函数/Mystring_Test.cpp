#include "iostream"
using namespace std;
#include "Mystring.h"
//date:2018-10-05 14:06
//Author : null
//MySrting类案例_构造和析构函数


void main01()
{
	MyString s1;
	MyString s2("s2");
	MyString s2_2;
	MyString s3 = s2;
	MyString s4 = "s4444444";

	//测试运算符 重载 和 重载[]
	//=
	
	s4 = s2;
	s4 = "s2222";
	s4[1] = '4';
	pritnf("%c",s4[1]);

	cout<<s4<<endl;

	//ostream& operator<<(ostream &out,MyString &s)
	
	//char& operator[](int index);

	MyString& operator = (const char* p);
	MyString& operator = (const MyString& s);

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}


void main02()
{
	MyString s1;
	MyString s2("s2");

	MyString s3 = s2;

	bool operator==(const char *p);
	bool operator==(const MyString& s);

	bool operator!=(const char *p);
	bool operator!=(const MyString& s);


	if(s2 == "s2222")
	{
		printf("相等");
	}
	else
	{
		printf("不相等");
	}
	if(s3 == s2)
	{
		printf("相等");
	}
	else
	{
		printf("不相等");
	}
}


void main()
{
	MyString s1;
	MyString s2("s2");

	MyString s3 = s2;

	s3 = "aaa";

	int operator<(const char*p);
	int operator>(const char*p);

	int operator<(const MyString& s);
	int operator>(const MyString& s);

	if(a3 < "bbb")
	{
		printf("s3 小于 bbb");
	}
	else
	{
		printf("s3 大于 bbb");
	}

	if(a3 < s2)
	{
		printf("s3 小于 bbb");
	}
	else
	{
		printf("s3 大于 bbb");
	}

	MyString s3 = "aaafff";
	strcpy(s4.c_str(),"aaa111");//MFC
	cout<<s4<<endl;
}

void mian()
{
	MyString s1(128);//给s1分配128个字节
	/*cin>>s1;*/

	cout<<"\n请输入字符串(回车结束)";
	cin>>s1;

	cout<<s1<<endl;

	system("pause");
/*	istream operator>>(iostream &in,MyString &s)*/
	
}