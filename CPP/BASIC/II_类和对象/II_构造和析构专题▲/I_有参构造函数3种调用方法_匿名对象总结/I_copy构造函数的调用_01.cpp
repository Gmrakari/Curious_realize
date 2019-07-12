
#include "iostream"
using namespace std;

//date:2018-09-02 09:58
//Author : null
//copy构造函数的调用_01

class Location
{
public:
	Location(int xx= 0,int yy = 0)
	{
		X = xx;Y = yy;
		cout<<"Constructro Object."<<endl;
	}
	//copy 构造函数，完成对象的初始化
	Location(const Location &obj)//copy构造函数
	{
		X = obj.X;
		Y = obj.Y;
	}
	~Location()
	{
		cout<<X<<","<<Y<<"Object destroyed"<<endl;
	}

	int GetX()
	{
		return X;
	}
	int GetY()
	{
		return Y;
	}
private:
	int X,Y;
};

void f(Location p)
{
	cout<<p.GetX()endl;
}

void playobj()
{
	Location a(1,2);
	Location b = a;
	cout<<"b对象经完成初始化完毕"<<endl;
	f(b);
}

void main()
{
	playobj();

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
