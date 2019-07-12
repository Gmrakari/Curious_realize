#include "iostream"
using namespace std;

//复杂数据类型的 引用

struct Teacher{
	char name[64];
	int age;
};

void printfT(Teacher *pT)
{
	cout<<pT-<age<<endl;
}
//pT是t1的别名 相当于修改了t1
void printfT02(Teacher &pT)
{
	cout<<pT.age<<endl;
}

//pT和t1 是两个不同的变量
void printfT03(Teacher pT)
{
	cout<<pT.age<<endl;
	pT.age = 45;//只会修改pT,不会修改t1的变量
}

void main()
{
	Teacher t1;
	t1.age = 35;

	printfT(&t1);

	printfT02(t1);// pT是t1 的别名

	printfT03(t1);//pT是形参 ，t1 copy一份给pT //------>pT = t1;
	
	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}