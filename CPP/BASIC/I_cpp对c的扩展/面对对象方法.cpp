#include "iostream"//包含c++的头文件
using namespace std;//使用命名空间 std  标准的命名空间（在这个命名空间定义了很多标准定义）

int main()
{
	//cout 标准输出 黑屏幕 
	//<<左移操作符 在c++ 里面 功能的改造（增强）====>c++ 语言操作符重载
	cout << "hellocpp world" <<endl;
	return 0;

}

//求圆的面积
//用面向过程的方法求解圆形的面积
//<< >> 标准输入cin 和标准输出 始终卸载操作符的左边 
int main02()
{
	double r = 0;
	double s = 0;

	cout<<"请输入圆的半径:";
	//cin 代表输入 代表键盘
	cin >> r;

	cout<<"r的值是:"<<r<<endl;

	s = 3.14*r*r;
	cout<<"圆的面积是s:"<<s<<endl;

	return 0;
}

//在cpp中定义了 一个 自定义数据类型
struct Circle
{
	double m_r;//圆的半径 属性 成员变量
	double m_s;//圆的面积
};

//在cpp中定义一个自定义数据类型 MyCicle 
class MyCicle{
	
	public:	
	double m_r;//圆的半径 属性 成员变量
	double m_s;
	public :
		void setR(double r)//成员函数
		{
			m_r = r;
		}
		double getR()//成员函数
		{
			return m_r;
		}
		void getS()
		{
			m_s = 3.14*m_r*m_r;
			return m_s;
		}
	double m_s;
	protected:


}
//用面向对象的方法
//1、类的抽象 成员变量和成员函数
//2、实例化
//3、求面积
//面向过程加工的是一个个的函数
//面向对象加工的是一个一个的类

//思考1： 类的调用 执行过程分析==>类代码不是一步一步指向
//类是一个数据类型(固定大小的别名)
//定义一个类，是一个抽象的概念，不会给你分配内存
//思考2：cpp编译器是如何处理 多个对象，调用类的成员函数的,具体一点：如何区分是c1，c2，c3调用了getS
void main()
{

	MyCicle c1,c2,c3;//用类 定义 变量 对象（c1，对象）
	cout<<"请输入c1圆形的半径：";
	cin>>r;
	//给c1圆形的属性赋值
	c1.setR(r);

	cout<<"c1圆形的面积是:"<<c1.getS()<<endl;

	system("pause");
}
