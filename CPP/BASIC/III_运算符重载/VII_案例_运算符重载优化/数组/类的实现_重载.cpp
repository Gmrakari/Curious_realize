//date:2018-10-04 15:22 
//Author : null
//数组类案例 重载
//Project:2
#include "MyArray.h"

Array::Array(int length)
{
	if(length < 0)
	{
		//m_length = 0; debug
		length = 0;
	}
	m_length = length;
	m_space = new int[m_length];
}

//Array a2 = a1;
Array::Array(const Array& obj)
{
	this->m_length = obj.m_length;
	//深拷贝
	this->m_space = new int[this->m_length];//分配内存空间

	for(int i = 0;i< obj.lenth;i++)
	{
		this->m_space[i] = obj.m_space[i];//数据元素赋值
	}
}

Array::~Array()
{
	if(m_space != NULL)
	{
		delete[] m_space;
		m_length = 0;
	}
}

//a1,.setData(i,i);

void Array::setData(int index,int valude)
{
	m_space[index] = valude;
}
int Array::getData(int index)
{
	return m_space[index];
}
int Array::length()
{
	return m_length;
}

//
int Array::operator[](int i)
{

	return m_space[i];
}

//a3 = a1;
Array& operator(Arrray & a1)
{
	//1 释放原来的内存空间
	if(this->m_space ! = NULL)
	{
		delete [] m_space;
		m_length = 0;
	}
	//2根据a1大小 分配内存
	m_length = a1.m_length;
	m_space = new int[a1.m_length];

	//3 copy 数据
	
	for(int i = 0;i<m_length;i++0)
	{
		//m_space[i] = a1.m_space[i]
		m_space[i] = a1[i];
	}
	return *this;
}

/*if(a3 == a1)*/
bool Array::operator==(Array &a1)
{
	if(this->m_length != a1.m_length)
	{
		return false;
	}
	for(int i = 0;i<m_length;i++)
	{
		if(this->m_space[i] != a1[i])
		{
			return false;
		}
	}
	return ture;
}

/*if(a3 != a1)*/
bool Array::operator!=(Array &a1)
{
	/*if(*this == a1)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return !(*this == a1)
}
