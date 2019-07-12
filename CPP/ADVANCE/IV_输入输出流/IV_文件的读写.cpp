#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "fstream"

//date:2018-12-09 17 : 05 
//Author : null
//Project:文件的读写
//
void main1()
{
	char* fname = "c:/2.txt";
	ofstream fout(fname,ios::app | ios::ate);//建一个 输出流对象 和文件 关联
	if(!fout)
	{
		cout<<"文件打开失败"<<endl;
		return ;
	}
	fout<<"hello ... 111"<<endl;
	fout<<"hello ... 222"<<endl;
	fout<<"hello ... 333"<<endl;
	fout.close();

	//读文件
	
	ifstream fin(fname);//建立一个 输入流对象 和 文件关联 
	char ch;

	while(fin.get(ch))
	{
		cout << ch;
	}
	fin.close();


	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}

class Teacher
{
public:
	Teacher()
	{
		age = 33;
		strcpy(name,"");
	}
	Teacher(int age,char *_name)
	{
		age = _age;
		strcpy(name,_name);
	}
	void prinT()
	{
		cout<<"age :"<<age << "name: "<<name << endl;
	}
private:
	int age;
	char name[32];
};

void main()
{
	char *fname = "c:/11.dat";
	ofstream fout(fname,ios::binary);
	if(!fout)
	{
		cout<<"打开文件失败"<<endl;
		return ;
	}
	Teacher t1(31,"t31");
	Teacher t2(32,"t32");
	fout.write((char *)&t1,sizeof(t1));
	fout.write((char *)&t2,sizeof(t2));
	fout.close();

	//
	ifstream fin(fname);//建立一个输入流对象 和 文件关联
	Teacher tmp;


	fin.read((char *)&tmp,sizeof(Teacher));
	tmp.prinT();

	fin.close();

	system("pause");


}