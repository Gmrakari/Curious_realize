#include "iostream"
using namespace std;

//date:2018-10-05 14:06
//Author : null
//MySrting类案例_构造和析构函数

//c中没有字符串  字符串类（c风格得字符串）
//空串 " "
class 
{
	friend ostream& operator<<(ostream &out,MyString &s);
	friend ostream& operator>>(ostream &in,MyString &s);
public:
	MyString(int len = 0);
	MyString(const char *p);
	MyString(const MyString& s);
	~MyString();

public:
	//重载 == !=
	bool operator==(const char *p) const;
	bool operator==(const MyString& s)const;

	bool operator!=(const char *p)const;
	bool operator!=(const MyString& s)const;
public:

	int operator<(const char*p);
	int operator>(const char*p);

	int operator<(const MyString& s);
	int operator>(const MyString& s);

	//重载=
public:
	MyString& operator = (const char* p);
	MyString& operator = (const MyString& s);
	char& operator[](int index);

//把类的私有指针 露出来
public:
	char *c_str()
	{
		return m_p;
	}
	const char *c_str2()
	{
		return m_p;
	}
	int length()
	{
		return m_len;		
	}

private:
	int m_len;
	char *m_p;


};
