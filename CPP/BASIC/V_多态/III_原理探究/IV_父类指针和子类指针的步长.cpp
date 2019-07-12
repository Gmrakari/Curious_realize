#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-29 
//Author : null
//父类指针和子类指针的步长

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		print();
	}
	virtual void pirnt()
	{
		cout<<"我是父类"<<end;
	}
private:
	int a;
};

//成功，一次偶然的成功，比必然的失败更可怕
class Child : public Parent
{
public:
	/*Child(int a = 0,int b = 0):Parent(a)
	{
		this->b = b;
		print();
	}*/

	/*Child(int b = 0):Parent(0)
	{
		this->b = b;
	}*/
	virtual void pirnt()
	{
		cout<<"我是子类"<<end;
	}
private:
	int b;
};

void HowToPlay(Parent *base)
{
	base->print();//这里会有多态发生 //2动手脚 
}

void main()
{
	Child c1;//定义一个子类对象，在这个过程中，在父类构造函数中调用虚函数print 能发生多态吗?
	//c1.print();
	Parent *pP = NULL;
	//
	Child *oC =NULL;


	Child array[] = {Child(1),Child(2),Child(3)};

	pP = array;
	pC = array;

	pP->print();
	pC->print();//多态发生


	pP++;
	pC++;
	pP->print();
	pC->print();//多态发生


	pP++;
	pC++;
	pP->print();
	pC->print();//多态发生

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}