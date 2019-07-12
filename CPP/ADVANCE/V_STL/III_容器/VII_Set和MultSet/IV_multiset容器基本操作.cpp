#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "set"
//date:2019-06-29 17:04
//Author : null
//Project:multiset容器基本操作

void main1001()
{
	multiset<int> set1;

	printf("请输入multiset集合的值:");

	scanf("%d",&tmp);

	while(tmp != 0)
	{
		set1.insert(tmp);
		printf("请输入multiset集合的值:");
		scanf("%d",&tmp);
	}
	for(multiset<int>::iterator it = set1.begin();it != set1.end();it++)
	{
		cout<<*it<<" ";
	}

	while(!set1.empty())
	{
		multiset<int>::iterator it = set1.begin();
		cout<<*it<<" ";
		set1.erase(it);
	}

}

void main()
{
	main1001();
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	