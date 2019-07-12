/*
标题：次数差

x星球有26只球队，分别用a~z的26个字母代表。他们总是不停地比赛。

输入，一个串，表示球队获胜情况（保证串的长度<1000）

要求输出一个数字，表示出现次数最多的字母比出现次数最少的字母多了多少次。

比如：
输入：
abaabcaa

则程序应该输出：
4

解释：a出现5次，最多；c出现1次，最少。5-1=4

再比如：
输入：
bbccccddaaaacccc

程序应该输出：
6
 */

/*
 	@Author : Gmrakari
 	Data:10 March 2019 16:00
	Content: Practise
	The following thinking:
	1、定义一个数组，存储a~z的字母
	2、定义一个指针，存储输入的字符串
	3、通过遍历，找出相同的字符，出现相同的次数
	4、定义一个函数，找出最多/最少的次数
	5、返回结果
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	fun_define();
	fun_traversal();
	return 0;
}

int fun_define()
{
	char arr[25] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
	char *get_string;
	get_string = (char *)malloc(sizeof(char));
	scanf("%s",get_string);
}

int fun_traversal()
{
	while(get_arr[1024] !='\0')
	{
		//如果使用strchr的比较方法，显然使得程序操作冗杂，不方便（很low）
		/*
		if(strchr(get_arr[1024],a))
			a++;
		if(strchr(get_arr[1024],b))
			b++;
		if(strchr(get_arr[1024],c))
			b++;
		 */

		//有没有方法，就是我想让程序这么处理，在读入字符串的时候，它能够自己识别，然后进行相同的字符自增
		
		//我这么想，就是在我定义的指针中，每读取一个字符就录入到另外一个数组中并且比较，如果存在，那么就自增
		
	}

}

