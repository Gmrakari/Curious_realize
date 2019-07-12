#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-08 15 : 35 
//Author : null
//类型转换 dynamic_cast

/*
C风格的强制类型转换(Type Cast)很简单，不管什么类型的转换统统是：
TYPE b = (TYPE)a   

C++风格的类型转换提供了4种类型转换操作符来应对不同场合的应用。
　　　　	static_cast			静态类型转换。如int转换成char
		reinterpreter_cast	重新解释类型 
　　		dynamic_cast		命名上理解是动态类型转换。如子类和父类之间的多态类型转换。
		const_cast			字面上理解就是去const属性。
4种类型转换的格式：
	TYPE B = static_cast<TYPE> (a)
 */  

class Tree {};

class Animal
{
public:
	virtual void cry() = 0;
protected:
private:
};

class Dog:public Animal
{
public:
	virtual void cry()
	{
		cout<"wangwang"<<endl;
	}
	void doHome()
	{
		cout<<"watch Home"<<endl;
	}
};

class Cat:public Animal
{
public:
	virtual void cry()
	{
		cout<<"miaomiao"<<endl;
	}
	void doThing()
	{
		cout<"catch mouse"<<endl;
	}
};

void playObj(Animal *base)
{
	base->cry();// 1、有集成 2 虚函数重写 3父类指针 指向子类对象 ==>>多态
	// 能识别子类对象
	// dynamic_cast 运行时类型识别 R11T
	
	Dog *pDog = dynamic_cast<Dog *>(base);
	if(pDog != NULL)
	{
		pDog->doHome();
	}

	Cat *pCat = dynamic_cast<Cat *>(base);//父类 对象 ====>子类对象  向下转型
											//把老子 转成 小子 
	if(pCat != NULL)
	{
		pCat->doThing();
	}
}

int main()
{
	Dog d1;
	Cat c1;

	Animal *pBase = NULL;

	pBase = &d1;

	pBase = static_cast<Animal *>(&d1);//让cpp编译器 在编译的时候进行 类型检查

	//强类型转换
	pBase = reinterpret_cast<Animal *>(&d1);

	{
		Tree t1;
		pBase = static_cast<Animal *>(&t1);// cpp编译器会做类型检查
		pBase = reinterpret_cast<Animal *>(&t1);//reinterpret_cast重新解释 .. 强制类型转化的味道
	}
	playObj(&d1);
	playObj(&c1);

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}