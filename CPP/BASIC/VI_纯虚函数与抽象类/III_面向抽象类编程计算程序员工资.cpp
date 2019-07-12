#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-30 16:55
//Author : null
//calc程序员的工资

/*编写一个c++程序，计算程序员(programmer)工资
1、要求能计算出初级程序员(junior_programmer)，中级程序员(mid_programmer)高级程序员(adv_programmer)的工资
2、要求利用抽象类统一界面，方便程序的扩展，比如：新增，计算 架构师(architect)的工资*/

class Programmer
{
public:
	virtual void get_salary() = 0;
protected:
private:
};

//junior
class junior_programmer : public Programmer
{
public:
	junior_proprammer(char *name,char *job,int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void get_salary()
	{
		cout<<name<<" "<<job<<":"<<sal<<endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

//mid
class mid_programmer : public Programmer
{
public:
	mid_proprammer(char *name,char *job,int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void get_salary()
	{
		cout<<name<<" "<<job<<":"<<sal<<endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

//adv
class adv_programmer : public Programmer
{
public:
	adv_proprammer(char *name,char *job,int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void get_salary()
	{
		cout<<name<<" "<<job<<":"<<sal<<endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

//
class architect : public programmer 
{
public:
	architect(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout<<name<<" " << job << " : " << sal <<endl;
	}
private:
	char *name;
	char *job;
	int sal;
};


//计算函数  简答的框架
void CalProgSal(programmer *base)
{
	base->get_salary();
}

void main()
{
	Programmer *compolish = NULL:

	junior_programmer jp("小周","初级",5000);

	mid_programmer mp("小然","中级"，8000);

	adv_programmer ap("小明","高级",12000);

	architect ar("小林","架构师",24000);


	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);

	CalProgSal(&ar);

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	