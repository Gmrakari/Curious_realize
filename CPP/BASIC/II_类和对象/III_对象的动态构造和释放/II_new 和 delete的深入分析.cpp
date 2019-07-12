#include "iostream"
using namespace std;

//date:2018-09-04 14：58
//Author : null
//new 和 delete的深入分析

//结论：malloc 不会调用类的构造函数
//		Free 不会调用类的析构函数

void main()
{
	//c分配
	int *a = (int *)malloc(sizeof(int));
	*p = 10;
	//free(p);//用delete 程序 正常运行 
	delete p;

	//cpp分配数组
	
	int *pArray = new int[10];
	pArray[1] = 2;

	//delete [] pArray;//数组不要把[] 忘记
	free(pArray);

	//
	int *p3 = new int(30);
	printf("*p3:%d\n",*p3);
	delete p3;

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}