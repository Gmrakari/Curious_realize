#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "MyVector.h"
//date:2018-12-02 16 : 25 
//Author : null
//

template<typename T>
friend ostream & operator<<(ostream &out,MyVector<T> &obj)
{
	for(int i = 0;i < obj.m_len ; i++)
	{
		out<<obj.m_space[i]<<" ";
	}
	out<<endl;

	return out;  
}

//MyVector<int> myv(10)
template<typename T>
MyVector<T>::(int size = 0)//构造函数
{
	m_space = new T[size];
	m_len = size;
}

//MyVector<int> myv2= myv1; 
template<typename T>
MyVector<T>::MyVector(const MyVector &obj)//拷贝构造函数
{
	//根据myv1的大小分配内存
	m_len = obj.m_len;
	m_space = new T[m_len];

	//copy数据
	for(int i = 0;i < m_len;i++)
	{
		m_space[i] = obj.m_space[i];
	}
}

template<typename T>
MyVector<T>::~MyVector()//析构函数
{
	if(m_space != NULL)
	{
		delete [] m_space;
		m_space = NULL;
		m_len = 0;
	}
}


template<typename T>
T& MyVector<T>:: operator[](int index)
{
	return m_space[index];
}

//a3 = a2 = a1;
template<typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector &obj)
{
	//先把a2旧的内存释放掉
	if(m_space != NULL)
	{
		delete [] m_space;
		m_space = NULL;
		m_len = 0;
	}

	//根据a1分配内存
	m_len = obj.m_len;
	m_space = new T[m_len];

	//copy数据
	for(int i = 0;i < m_len;i++)
	{
		m_space[i] = obj[i];
	}
	//a 2 = a1 ;返回a2的自身
	return *this;
}

T *m_space;
int m_len;