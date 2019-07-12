//bool类型
#include "iostream"
using namespace std;

int main()
{
	bool b1 = true;//告诉cpp编译器给我分配1哥字节的内存

	cout<<"sizeof(bool)"<<sizeof(bool)<<endl;

	b1 = 10;

	cout<<"b1:"<<b1<<endl;//bool变量 1 或者 0

	b1 = 0;

	cout<<"b1:"<<b1<<endl;//bool变量 1 或者 0

}