#include "iostream"
using namespace std;
#include "Mystring.h"
#define _CRT_SECURE_NO_WARNINGS
//date:2018-10-05 14:06
//Author : null
//MySrting类案例_构造和析构函数

ostream& operator<<(ostream &out,MyString &s)
{
	out<<s.m_p;
	return out;
}
istream& operator>>(iostream &in,MyString &s)
{
	cin>>s.m_p;
	return in;
}

MyString::MyString()
{
	if(len == 0)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strpy(m_p,"");
	}
	else
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		memset(m_p,0,m_len);
	}
	
}

MyString::MyString(const char *p)
{
	if(p == NULL)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p,"");
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p,p);
	}
}

//拷贝构造函数
//MyString s3 = s2;
MyString::MyString(const MyString& s)
{
	m_len = s.m_len;
	m_p = new char[m_len + 1];

	strcpy(m_p,s.m_p);
}

MyString::~MyString()
{
	if(m_p != NULL)
	{
		delete [] m_p;
		m_p = NULL;
		m_len = 0;
	}
}

//s4 = "s2222";
MyString& operator = (const char* p)
{
	//旧内存释放掉
	if(m_p != NULL)
	{
		delete [] m_p;
		m_len = 0;
	}
	//2根据p分配内存
	if(p == NULL)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p,"");
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p,p);
	}
	return *this;
}

//s4 = s2;
MyString& operator = (const MyString &s)
{
	//旧内存释放掉
	if(m_p != NULL)
	{
		delete [] m_p;
		m_len = 0;
	}
	//2根据s分配内存
	
	m_len = s.m_len;
	m_len = strlen(p);
	m_p = new char[m_len + 1];
	strcpy(m_p,s.m_p);

	return *this;

}

char& MyString::operator[](int index)
{
	return m_p[index];
}


//if(s2 == "s22222")
bool MyString::operator==(const char *p) const
{
	if(p == NULL)
	{
		if(m_len == 0)
		{
			return true;
		}
		else
			return false;
	}
	else
	{
		if(m_len == strlen(p))
		{
			return !strcmp(m_p,p);
		}
		else
		{
			return false;
		}
	}
}

bool MyString::operator!=(const char *p) const
{
	return !(*this == p);
}

bool MyString::operator==(const MyString& s) const
{
	if(m_len != s.m_len)
	{
		return false;
	}
	return !strcmp(m_p,s.m_p)
}

bool MyString::operator!=(const MyString& s) const
{
	return !(*this ==s);
}

//if(s3 < "bbb")

int MyString::operator<(const char*p)
{
	return strcmp(this->m_p,p);
}
int MyString::operator>(const char*p)
{
	return strcmp(p,this->m_p);
}

int MyString::operator<(const MyString& s)
{
	return strcmp(this->m_p,s.m_p);
}

int MyString::operator>(const MyString& s)
{
	return strcmp(s.m_p,m_p);
}

istream& operator>>(iostream &in,MyString &s)
{

}

