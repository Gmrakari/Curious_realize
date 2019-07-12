#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-12-08 11 : 05 
//Author : null
//Projext:异常类型_异常变量的生命周期

//传统的错误处理机制 
//throw int 类型异常
void my_strcpy1(char *to,char *from)
{
	if(from == NULL)
	{
		throw 1;
	}
	if(to == NULL)
	{
		throw 2;
	}

	// copy  场景检查
	if(*from == 'a')
	{
		throw 3;//copy时出错
	}
	while(*from != '\0')
	{
		*to = *from;
		to ++;
		from ++;
	}
	*to = '\0';
}


//传统的错误处理机制 
//throw char * 类型异常
void my_strcpy2(char *to,char *from)
{
	if(from == NULL)
	{
		throw "源buf出错";
	}
	if(to == NULL)
	{
		throw "目的buf出错";
	}

	// copy  场景检查
	if(*from == 'a')
	{
		throw "copy过程出错";//copy时出错
	}
	while(*from != '\0')
	{
		*to = *from;
		to ++;
		from ++;
	}
	*to = '\0';
}


class BadSrcType 
{
	BadSrcType()
	{
		cout<<"BadSrcType构造函数do\n";
	}
};
class BadDestType 
{
public:
	BadDestType()
	{
		cout<<"BadDestType构造函数do\n";
	}
	~BadDestType()
	{
		cout<<"BadDestType析构函数do\n";
	}
};
class BadProcessType 
{
public:
	BadProcessType()
	{
		cout<<"BadProcessType构造函数do\n";
	}
	~BadProcessType()
	{
		cout<<"BadProcessType析构函数do\n";
	}
};


//传统的错误处理机制 
//throw 类对象 类型异常
void my_strcpy3(char *to,char *from)
{
	if(from == NULL)
	{
		throw BadSrcType();
	}
	if(to == NULL)
	{
		throw BadDestType();
	}

	// copy  场景检查
	if(*from == 'a')
	{
		throw BadProcessType();//会不会产生 匿名对象
	}
	if(*from == 'b')
	{
		throw& (BadProcessType());//会不会产生一个匿名对象
	}
	if(*from == 'c')
	{
		throw new (BadProcessType());//会不会产生一个匿名对象
	}
	while(*from != '\0')
	{
		*to = *from;
		to ++;
		from ++;
	}
	*to = '\0';
}


void main()
{
	int ret = 0;
	char buf1[] = "cbcdefg";
	char buf2[1024] = {0};

	try
	{
		//my_strcpy1(buf2,buf1);
		//my_strcpy2(buf2,buf1);
		my_strcpy3(buf2,buf1);
	}
	catch(int e)//e 可以写 也可以不用写
	{
		cout<<e<<"int 类型异常"<<endl;
	}
	catch(int *e)
	{
		cout<<e<<"char * 类型异常"<<endl;
	}
	catch(...)
	{
		cout<<"未知异常"<<endl;
	}


	// -- -
	catch(BadSrcType e)
	{
		cout<<<<"BadSrcType 类型异常"<<endl;
	}

	catch(BadDestType e)
	{
		cout<<<<"BadDestType 类型异常"<<endl;
	}

	//结论1、如果 接受异常的时候 使用一个异常变量 则copy构造异常变量
/*	catch(BadProcessType e)//是把匿名对象 copy给e 还是e 那个匿名对象
	{
		cout<<<<"BadProcessType 类型异常"<<endl;
	}
*/

	//结论2、 使用引用的话 会使用throw 时候的 那个对象
/*	catch(BadProcessType &e)//是把匿名对象 copy给e 还是e 那个匿名对象
	{
		cout<<<<"BadProcessType 类型异常"<<endl;
	}
*/

	//结论3、指针可以和引用/元素 写在一块 但是引用/元素不能写在一块
	catch(BadProcessType *e)//是把匿名对象 copy给e 还是e 那个匿名对象
	{
		cout<<<<"BadProcessType 类型异常"<<endl;
		delete e;
	}
	catch(...)
	{

	}
	// -- -

	
/*	ret= my_strcpy(buf2,buf1);
	if(ret != 0)
	{
		switch(ret)
		{
			case 1:
			printf("源buf出错");
			break;
			
			case 2:
			printf("目的buf出错");
			break;

			case 3:
			printf("copy过程出错");
			break;

			default:
			printf("未知错误");
			break;
		}
	}
	printf("buf2:%s\n",buf2);
*/

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}