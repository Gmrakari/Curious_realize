#include <iostream.h>


//date:2018-11-1  10:00
//Author : null
//
//
#define PI 3.1416

class container
{
protected:
	double radius;
public:
	container(double radius)
	{
		container::radius = radius;
	}
	virtual double surfaceArea() = 0;
	virtual double volume() = 0;
};

class cube:public container 
{
public:
	cube (double radius ):container(radius)
	{

	};
	double surfaceArea()
	{
		return radius *radius;
	}
	double volume()
	{
		return radius *radius * raidus;
	}
};

class sphere:public container
{
public:
	sphere(double radius):container(radius){};
	double surfaceArea()
	{
		return 4*PI*radius*raidus;
	}
	double volume()
	{
		return PI*radius*radius*raidus*4/3;
	}
};

class cylinder:public container
{
	double height;
public:
	cylinder(double radius,double height):container(radius)
	{
		cylinder::height = height;
	}
	double surfaceArea()
	{
		return 2*PI*radius*(radius + height);
	}
	double volume()
	{
		return PI*radius*radius*height;
	}
};

void main()
{
	container *p;
	cube objCube(10);
	sphere objSphere(6);
	cylinder objCylinder(4,5);

	p = &objCube;

	cout<<"输出结果:"<<endl;
	cout<<"正方体表面积:"<<p->surfaceArea()<<endl;
	cout<<"正方体体积:"<<p->volume()<<endl;

	p = objSphere;

	cout<<"输出结果:"<<endl;
	cout<<"正方体表面积:"<<p->surfaceArea()<<endl;
	cout<<"正方体体积:"<<p->volume()<<endl;
}
