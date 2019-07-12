//指针的引用
//Date : 208-08-28 A.m.


#include "iostream"
using namespace std;

struct Teacher
{
	char name[64];
	itn age;
};

//在被调用函数 获取资源
int getTeacher(Teacher **p)
{
	Teacher *tmp = NULL;
	if(p == NULL)
	{
		return -1;
	}
	tmp = (Teacher *)malloc(sizeof(Teacher));
	if(tmp == NULL)
	{
		return -2;
	}
	//p是实参的地址， * 实参的地址，去间接的修改实参的值
	*P = tmp;
}

int getTeacher2(Teacher * &myp)
{
	//给myp 赋值 相当于给main函数中的pT1赋值
	myp = (Teacher *)malloc(sizeof(Teacher));
	if(myp == NULL)
	{
		return -1;
	}
	myp->age = 36;
}

void FreeTeacher(Teacher *pT1)
{
	if(pT1 == NULL)
	{
		return;
	}
	free(pT1);
}

void main()
{
	Teacher *pT1 = NULL;
	getTeacher(&pT1);
	cout<<"age:"pt1->age<<endl;	
	FreeTeacher(pT1);

// 2、cpp中的引用（指针的引用)
// 引用的本质：间接赋值后两个条件 ，让cpp编译器 帮我们完成
	getTeacher2(&pT1);
	cout<<"age:"pt1->age<<endl;
	FreeTeacher(pT1);

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
