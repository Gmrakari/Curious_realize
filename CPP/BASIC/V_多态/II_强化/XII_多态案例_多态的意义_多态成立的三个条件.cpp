#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-10-28 14:00
//Author : null
//多态案例_多态的意义_多态成立的三个条件


//HeroFighter AdvHeroFighter EnemyFighter

class HeroFighter
{
public:
	virtual int power()
	{
		return 10;
	}
};

class EnemyFighter
{
public:
	int attack()
	{
		return 15;
	}
};

class AdvHeroFighter:public HeroFighter
{
public:
	virtual int power()
	{
		return 20;
	}
};

//多态威力
//1 PlayObj给对象搭建舞台  看成一个框架
//Data:2018-10-28 14:23
void PlayObj(HeroFighter *hf,EnemFighter *ef)
{
	if(hf->power() > ef.attack())//hf->power() 函数调用会有多态发生
	{
		cout<<"主角win"<<endl;
	}
	else
	{
		cout<<"主角挂了"<<endl;
	}
}

class AdvAdvHeroFighter : public HeroFighter
{
public:
	virtual int power()
	{
		return 30;
	}
}


//多态的思想
//封装：突破了C函数的概念 ,,用类坐函数参数的时候，可以使用对象的属性 和 对象的方法
//继承：A B 代码的复用 
//多态：可以使用未来
//
//

//多条很重要
//实现多态的三个条件
//C语言 间接赋值是指针存在的最大意义 ,是C语言的特有的现象（1、定义两个变量 2 建立关联 3 *p在被调用函数去间接修改形参的值)

//1、要有继承
//2、要有虚函数重写
//3、用父类指针（父类引用）指向子类对象..
//

void main()
{
	HeroFighter hf;
	AdvHeroFighter Advhf;
	EnemyFighter ef;

	AdvAdvHeroFighter advadvhf;

	PlayObj(&hf,&ef);
	PlayObj(&advhf,&ef);

	PlayObj(&advadvhf,&ef);//这个框架 能把我们后来人写的代码，给调用起来
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}


int main01()
{
	HeroFighter hf;
	AdvHeroFighter Advhf;
	EnemyFighter ef;

	if(hf.power() > ef.attack())
	{
		cout<<"主角win"<<endl;
	}
	else
	{
		cout<<"主角挂了"<<endl;
	}
	if(Advhf.power() > ef.attack())
	{
		cout<<"Adv 主角win"<<endl;
	}
	else
	{
		cout<<"Adv 主角挂了"<<endl;
	}
	cout<<"hellc"<<endl;

	return 0;
}