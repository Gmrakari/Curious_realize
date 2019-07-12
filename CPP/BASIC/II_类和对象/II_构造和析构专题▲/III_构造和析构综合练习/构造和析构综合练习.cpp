#include "iostream"
using namespace std;

//date:2018-09-04 12:13
//Author : null
//构造和析构综合练习
class ABCD
{
public:
	ABCD(int a,int b,int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		printf("ABCD() construct ,a : %d,b : %d,c : %d \n",this->a,this->b,this->c);
	}
	~ABCD()
	{
		printf("~ABCD() construct,a : %d,b : %d,c : %d \n",this->a,this->b,this->c);
	}
	int getA()
	{
		return this->a;
	}
protected:
private:
	int a;
	int b;
	int c;
};

class MyE
{
public:
	MyE():abcd1(1,2,3),abcd2(4,5,6),m(100)
	{
		cout<<"MyD()"<<endl;
	}
	~MyE()
	{
		cout<<"~MyD()"<<endl;
	}
	MyE(const MyE & obj):abcd1(7,8,9),abcd2(10,11,12),m(100)
	{
		printf("MyD(const MyD & obj)\n");
	}
protected:
	//private:
public:
	ABCD abcd1;
	ABCD abcd2;
	const int m;
};

int doThing(MuE mye1)
{
	printf("doThing() mye1.abcd1.a:%d\n",mye.abcd1.getA());
	return 0;
}

int run2()
{
	MyE myE;
	doThing(myE);
	return 0;
}

int run3()
{
	printf("run3 start ..\n");

	//ABCD(400, 500, 600); //ÁÙÊ±¶ÔÏóµÄÉúÃüÖÜÆÚ  
	
	ABCD abcd = ABCD(100,200,300);
	//ÈôÖ±½Óµ÷ÓÃ¹¹Ôìº¯ÊýÄØ£¿
	//Ïëµ÷ÓÃ¹¹Ôìº¯Êý¶Ôabc¶ÔÏó½øÐÐÔÙ¸´ÖÆ£¬¿ÉÒÔÂð£¿
	//ÔÚ¹¹Ôìº¯ÊýÀïÃæµ÷ÓÃÁíÍâÒ»¸ö¹¹Ôìº¯Êý£¬»áÓÐÊ²Ã´½á¹û£¿

	printf("run3 end\n");
}

void main()
{
	//run2();
	
	run3();

	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
