#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;

//date:2018-11-20 16:21 
//Author : null
//函数模板 本质：类型参数 初始化
//函数模板当函数参数强化
//让你对字符数组 int数组进行排序
//
template<typename T,typename T2>
int mySort(T *array,T2 size)
{
	T2 i,j;
	T tmp;
	if(array == NULL)
	{
		return -1;
	}
	for(int i = 0;i<size ;i++)
	{
		for(j = i + 1;j<size;j++)
		{
			if(array[i] < array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}

		}
	}
	return 0;
}

template<typename T,typename T2>

int myPrint(T *array,T2 size)
{
	T2 i = 0;
	for(i = 0;i<size;i++)
	{
		/*cout<<(*array+i)<<endl;*/
		cout<<array[i] <<""<<endl;
	}
	return 0;
}

void main()
{
	// int 类型
	{
		int myarray [] = {11,44,33,22,3,6,9};
		int size = sizeof(myarray)/sizeof(*myarray);
		mySort<int,int>(myarray,size);

		printf("排序之后:\n");
	}

	//char 类型
	{
		char buf[] = "afff2aa42dssa";
		int len = strlen(buf);

		mySort<char,int>(buf,len);
		myPrint<char,int>(buf,len);

	}

	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}

			/*if(array[0] < (*array)+1)
			{
				int temp = 0;
				 temp =（*array）+ 1;
				（*array）+ 1 = array[0];
				array[0] = temp;
			}*/