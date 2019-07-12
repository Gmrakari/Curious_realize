#include "iostream"
using namespace std;

//date:2018-10-05 11：27
//Author : null
//重载()


class F
{
public:
	int operator()(int a,int b)
	{
		return a*a + b*b;
	}
protected:
private:

};

class F2
{
public:
	int Myfunc(int a,int b)
	{
		return a*a + b*b;
	}
protected:
private:

};

void main()
{
	
	F f;
	f(2,4);

	F2 f2;
	f2.Myfunc(2,4);

	//
	//operator() (int a,int b)


	cout<<"helloc"<<endl;
	system("pause");
	return 0;
}
