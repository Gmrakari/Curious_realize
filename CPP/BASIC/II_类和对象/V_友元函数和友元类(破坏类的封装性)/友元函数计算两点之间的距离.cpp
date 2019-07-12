#include "iostream"
using namespace std;
#include "math.h"

//date:2018-09-08 11:09
//Author : null
//Project: 友元函数计算两点之间的距离

class Point 
{
public:
	Point(double xi,double yi)
	{
		X = xi;
		Y = yi;
	}
	double GetX()
	{
		return X;
	}
	double GetY()
	{
		return Y;
	}

	friend double Distance(Point &a,Point &b);
private:
	double X,Y;
};

double Distance(Point &a,Point &b)
{
	double dx = a.X-b.X;
	double dy = a.Y-b.Y;
	return sqrt(dx*dx + dy*dy);
}

void main()
{
	Porint p1(3.0,5.0),p2(4.0,6.0);
	double d = Distance(p1,p2);
	cout<<"this distance is "<<d<<endl;
}