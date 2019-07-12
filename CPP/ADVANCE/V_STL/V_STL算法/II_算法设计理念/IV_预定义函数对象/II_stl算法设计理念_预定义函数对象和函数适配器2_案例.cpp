#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include <list>
#include <algorithm>
#include "functional"
#include <vector>
#include "set"

//date:2019-07-06 10：05
//Author : null
//Project:stl算法设计理念_预定义函数对象和函数适配器2_案例

//函数适配器的分类：
//1、绑定适配器 (bind adaptor)
//2、组合适配器(composite adaptor)
//3、指针函数适配器(pointer function adaptor)
//4、成员函数适配器(menber function adaptor)

//plus<int> 预定好的函数对象，能实现不同类型的数据的+运算
//实现了 数据类型 和算法 的分类 ===> 通过函数对象技术实现的

//思考:怎么知道 plus<type> 是两个参数 
void main21()
{
	/*
	template<class _ty>
	struct plus:public binary_function<_Ty,_Ty,_Ty>
	{
		//functor for operator+
		_TY operator()(const _Ty& _Left,const _Ty& _Right) const
		{
			//apply operator+ to operands
			return (_Left + _Right);
		}
	}
	*/

	plus<int> intAdd;
	int x = 10;
	int y = 20;
	int z = intAdd(x,y);//equal x plus y 
	cout<<"z:"<<z<<endl;


	plus<string> stringAdd;
	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = stringAdd(s1,s2);
	cout<<"s3: "<<s3<<endl;

	vector<string> v1;
	v1.push_back("bbb");
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("zzz");
	v1.push_back("ccc");
	v1.push_back("ccc");
	v1.push_back("ccc");
	/*
	template<class _Ty>
	struct greater:public binary_function<_Ty,_Ty,_Ty>
	{
		//functor for operator+
		_TY operator()(const _Ty& _Left,const _Ty& _Right) const
		{
			//apply operator+ to operands
			return (_Left + _Right);
		}
	}
	*/	

	sort(v1.begin(),v1.end(),greater<string>());

	for(vector<string>::iterator it = v1.begin();it != v1.end();it++)
	{
		cout<<*it<<endl;
	}

	//求ccc出现的个数
	string sc = "ccc";

	//equal_to<string>() 有两个参数 left参数来自容器 ,right参数来自sc
	//bind2nd 函数适配器 作用:把预定义函数对象 和 第二个参数 进行绑定
	int num = count_if(v1.begin(),v1.end(),bind2nd( equal_to<string>(),sc));
	cout<<"num: "<<num<<endl;
}

struct IsGreat
{
public:
	IsGreat(int i)
	{
		m_num = i;
	}
	bool operator()(int &num)
	{
		if(num > m_num)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	int m_num;

};

void main22()
{
	vector<int> v1;
	for(int i = 0;i < 10 ;i++)
	{
		v1.push_back(i+1);
	}
	for(vector<int>::iterator it = v1.begin();it !=v1.end();it++)
	{
		cout<<*it<<endl;
	}

	cout<<endl;
	int num1 = count(v1.begin(),v1.end(),3);
	cout<<"num1: "<<num1<<endl;

	//通过谓词 求 大于2 的个数
	int num2 = cout_if(v1.begin(),v1.end(),IsGreat(2));
	cout<<"num2: "<<num2<<endl;

	/*
	template<class _Ty>
	struct greater:public binary_function<_Ty,_Ty,bool>
	{
		//functor for operator+
		_TY operator()(const _Ty& _Left,const _Ty& _Right) const
		{
			//apply operator+ to operands
			return (_Left + _Right);
		}
	}
	*/

	//通过预定义的函数对象 求大于2 的个数
	//greater<int>() 有两个参数 做参数来自容器的元素，右参数固定成2 （通过bind2nd做的）
	int num3 = cout_if(v1.begin(),v1.end(),bind2nd(greater<int>(),2));
	cout<<"num3: "<<num3<<endl;

	//求 奇数的个数
	
	int num4 = count_if(v1.begin(),v1.end(),bind2nd(modulus<int>(),2));
	cout<<"num4: "<<num4<<endl;

	//求 偶数的个数 取反器(negator)

	int num5= count_if(v1.begin(),v1.end(),notl(bind2nd(modulus<int>(),2)));
	cout<<"num5: "<<num5<<endl;	

}

int main()
{
	//main21();
	main22();

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}