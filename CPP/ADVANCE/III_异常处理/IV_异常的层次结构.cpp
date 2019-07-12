#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-09 10 : 50
//Author : null
//Project:异常的层次结构


class MyArray
{
public:
	MyArray(int len);
	~MyArray();
public:
	int &operator[](int index);
	int getLen();

	class eSize
	{
	public:
		eSize(int size)
		{
			m_size = size;
		}
		virtual void printErr()
		{
			cout<<"size: "<<m_size<<endl;
		}
	protected:
		int m_size;

	};
	class eNegative : public eSize
	{
	public:
		eNegative(int size):eSize(size)
		{
			;
		}
		virtual void printErr()
		{
			cout<<"eNegative::size 类型"<<m_size<<endl;
		}
	};
	class eZero : public eSize
	{
	public:
		eZero(int size):eSize(size)
		{
			;
		}
		virtual void printErr()
		{
			cout<<"eZero::size 类型"<<m_size<<endl;
		}
	};	
	class eTooBig : public eSize
	{
	public:
		eTooBig(int size):eSize(size)
		{
			;
		}
		virtual void printErr()
		{
			cout<<"eTooBig::size 类型"<<m_size<<endl;
		}		
	};
	class eTooSmall : public eSize
	{
	public:
		eTooSmall(int size):eSize(size)
		{
			;
		}
		virtual void printErr()
		{
			cout<<"eTooSmall::size 类型"<<m_size<<endl;
		}		
	};

private:
	int *m_space;
	int m_len;
};

MyArray::MyArray(int len)
{
	if(len < 0) 
	{
		throw eNegative();
	}
	if else (len == 0)
	{
		throw eZero(len);
	}
	else if(len > 1000)
	{
		throw eTooBig(len);
	}
	else if(len < 3)
	{
		throw eTooSmall(len);
	}

	m_len = len;
	m_space = new int[len];
}

MyArray::~MyArray()
{
	if(m_space != NULL)
	{
		delete [] m_space;
		m_space = NULL;
		m_len = 0;
	}
}

int MyArray::getLen()
{
	return m_len;
}

int & MyArray::operator[](int index)
{
	return m_space[index];
}


void main()
{
	try
	{
		MyArray a(-5);
		for(int i = 0;i < a.getLen();i++)
		{
			a[i] = i + 1;
			printf("%d",a[i]);

		}
	}
	catch(MyArray::eSize &e)
	{
		cout<<"len 的大小"<<e.eSize()<<;
		e.printErr();
	}
	catch(...)
	{

	}
/*	MyArray a(5);*/

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}



//不推荐使用繁重的方法
void main01()
{
	try
	{
		MyArray a(-5);
		for(int i = 0;i < a.getLen();i++)
		{
			a[i] = i + 1;
			printf("%d",a[i]);

		}
	}
	catch(MyArray::eNegative e)
	{
		cout<<"eNegative类型异常"<<endl;
	}
	catch(MyArray::eZero e)
	{
		cout<<"eZero类型异常"<<endl;
	}
	catch(MyArray::eTooBig e)
	{
		cout<<"eTooBig类型异常"<<endl;
	}
	catch(MyArray::eTooSmall e)
	{
		cout<<"eTooSmall类型异常"<<endl;
	}
	catch(...)
	{

	}
	MyArray a(5);

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}