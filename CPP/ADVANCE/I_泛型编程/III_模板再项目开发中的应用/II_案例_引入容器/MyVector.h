#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-02 16 : 25 
//Author : null
//

template<typename T>
class MyVector
{
	friend ostream & operator<< <T>(ostream &out,MyVector &obj);	
public:
	MyVector(int size = 0);//构造函数
	MyVector(const MyVector &obj);//拷贝构造函数
	~MyVector();//析构函数
public:
	T& operator[](int index);

	MyVector *operator operator=(const MyVector &obj);	


public:
	int getLen()
	{
		return m_len;
	}

protected:
	T *m_space;
	int m_len;
private:

};