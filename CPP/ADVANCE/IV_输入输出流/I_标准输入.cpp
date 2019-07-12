#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-08 11 : 05 
//Author : null
//Project:标准输入流对象cin
/*
		cin.get()//一次只能读取一个字符
		cin.get(一个参数)//读一个字符
		cin.get(三个参数)//可以读字符串
		cin.getline()
		cin.ignore()
		cin.peek()
		cin.putback()
*/
void main()
{
	char mybuf[1024];
	int myInt;
	long myLong;

	cin >> myInt;

	cin >> myLong;

	cin >>mybuf;//遇到空格 停止接受 数据

	cout << "myInt"<<myInt<<"myLong"<<myLong<<"mybuf"<<mybuf<<endl;
	

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}

void main()
{
	char ch;

	whule((ch = cin.get())!= EOF)
	{
		cout<<ch<<endl;
	}

}

void main()
{
	char a,b,c;
	cout << "cin.get(a)如果缓冲区没有数据，则程序阻塞\n";
	cin.get(a);
	cin.get(b);
	cin.get(c);

	cout << a << b << c<<"因为缓冲区有数据 程序不会阻塞\n";

	cin.get(a).get(b).get(c);

	cout<< a << b << c;
}


//getline函数可以接受空格
void main()
{
	char buf1[256];
	char buf2[256];

	cout<<"请输入一个字符串 含有多个空格 aa bb cc dd\n";

	cin >> buf1;

	cin.getline(buf1,256);

	cout <<" buf1: "<< buf1 << "buf2: "<< buf2<<endl;

}