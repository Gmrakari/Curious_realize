#include "iostream"
using namespace std;
//Date:2018-08-30 17:10
//Author:null
//面向过程向面向对象转变的案例
class Cube
{
public:
	void setA(int a)
	{
		m_a = a;
	}
	void setB(int b)
	{
		m_b = b;
	}
	void setC(int c)
	{
		m_c = c;
	}

	void setABC(int a = 0, int b = 0, int c = 0)
	{
		m_a = a; m_b = b; m_c = c;
	}

	int getA()
	{
		return m_a;
	}

	int getB()
	{
		return m_b;
	}

	int getC()
	{
		return m_c;
	}

public:
	int getV()
	{
		m_v = m_a*m_b*m_c;
		return m_v;
	}
	int getS()
	{
		m_s = 2 * (m_a*m_b + m_a*m_c + m_b*m_c);
		return m_s;
	}

	int judegeCube(Cube &v1, Cube &v2)
	{
		if (v1.getA() == v2.getA() && v1.getB() == v2.getB() && v1.getC() == v2.getC())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int judegeCube( Cube &v2)//成员函数 函数重载
	{
		//分不清 这个场景下 m_a 是属于V1的还是v2的 或者是vn的
		if (m_a == v2.getA() && m_b == v2.getB() && m_c == v2.getC())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

protected:
private:
	int m_a;
	int m_b;
	int m_c;
	int m_v;
	int m_s;
};
//全局函数
//1相等 0不相等

int judegeCube(Cube &v1, Cube &v2)
{
	if (v1.getA() == v2.getA() && v1.getB() == v2.getB() && v1.getC() == v2.getC())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main_调用类函数()
{
	Cube v1, v2;
	v1.setABC(1, 2, 3);
	cout << v1.getS() << endl;
	cout << v1.getV() << endl;

	v2.setABC(1, 2, 4);
	v1.judegeCube(v1, v2);

	//判断练个立方体是否相等
	//
	if (v1.judegeCube(v1, v2) == 1)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	cout << "helloc" << endl;
	system("pause");
	return 0;
}

int main_全局函数的调用()
{
	Cube v1, v2;
	v1.setABC(1, 2, 3);
	cout << v1.getS() << endl;
	cout << v1.getV() << endl;


	//判断练个立方体是否相等
	//
	if (judegeCube(v1, v2) == 1)
	{
		cout <<"相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	cout << "helloc" << endl;
	system("pause");
	return 0;
}

int main()
{
	Cube v1, v2;
	v1.setABC(1, 2, 3);
	cout << v1.getS() << endl;
	cout << v1.getV() << endl;

	v2.setABC(1, 2, 4);

	//问题抛出
	//函数调用 ▲ 意味着：去执行v1对象的类的成员 judgeCube
	v1.judegeCube(v2);//判断v1立方体 和v2立方体是否相等 ，通过类的成员函数

	//判断练个立方体是否相等

	if (v1.judegeCube(v1, v2) == 1)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	cout << "helloc" << endl;
	system("pause");
	return 0;
}
