#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include <iomanip>//控制符

//date:2018-12-09 16 : 40
//Author : null
//Project:标准输出

/*

标准输出流对象cout
	cout.flush()
	cout.put()
	cout.write()
	cout.width()
	cout.fill()
	cout.setf(标记)
	*/

/*
manipulator(操作符、控制符)
flush
endl
oct
dec
hex
setbase
setw
setfill
setprecision
…
*/


void main2()
{
	cout << "hello" << endl;

	cout.put('h').put('e').put('l').put('l').put('o');

	char *p = "hello itcast";
	cout.write(p,strlen(p)) << endl;
	cout.write(p,strlen(p) - 4) << endl;
	cout.write(p,strlen(p) + 4) << endl;
	
	system("pause");
	return 0;
}

void main()
{
	//使用类成员函数
	cout<<"<start>";

	cout.width(30);
	cout.fill('*');

	cout.setf(ios::showbase);//#include <iomanip>
	cout.setf(ios::internal);//internal分离
	cout<<hex <<123<<"<END>\n";//hex 16进制

	cout<<endl<<endl;
	//使用控制符
	cout<<"<Start"
		<<setw(30)
		<<setfill('*')
		<<setiosflags(ios::showbase)//基数
		<<setiosflags(ios::internal)
		<<hex
		<<123
		<<"<END>\n"
		<<endl;

		system("pause");

}