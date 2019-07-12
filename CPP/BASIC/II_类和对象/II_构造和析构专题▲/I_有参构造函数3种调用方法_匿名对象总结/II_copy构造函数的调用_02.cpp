
#include "iostream"
using namespace std;

//date:2018-09-02 09:58
//Author : null
//copy构造函数的调用_02
//（copy构造函数的第四种应用场景）

class Location
{
public:
	Location(int xx= 0,int yy = 0)
	{
		X = xx;Y = yy;
		cout<<"Constructro Object."<<endl;
	}
	//赋值构造函数(copy 构造函数)
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
//g 函数 返回一个元素
//结论： 1、函数的返回值 是一个元素（复杂类型的)
//返回的是一个新的匿名对象（所以会调用匿名对象类的copy构造函数)

//结论2、匿名对象的去和留
//如果用匿名对象 初始化 另外一个同类型的对象，匿名对象转成有名对象
//如果用匿名对象  赋值给 一个同类型的对象，匿名对象 被析构

//设计者的思想：给你返回一个新对象（没有名字，匿名对象）

Location g()
{
	Location A(1,2);
	return A;//进行析构，跳到copy的构造函数
}

void objplay2()
{
	g();
}

void objplay3()//匿名对象的去和留
{
	//用匿名对象初始化m，此时 cpp编译器 直接把匿名对象转成m;从匿名转成有实名。

	Location m = g();
	printf("匿名对象，被扶正，不会析构掉\n");
	cout<<m.GetX()<<endl;
}

void objplay4() //匿名对象的去和留
{
	//用匿名对象 赋值给 m2 后 匿名对象被析构
	Location m2(1,2);
	m2 = g();
	printf("因为用匿名对象 = m2 ，匿名对象，被析构\n");
	cout<<m.GetX()<<endl;
}

void main()
{
	//objplay2();
	//objplay3();
	objplay4();

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}


class duixiang{
public:
	void 
private:
	int the_duixiang_all_thing;

}