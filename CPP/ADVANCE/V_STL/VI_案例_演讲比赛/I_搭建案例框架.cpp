#define  _CRT_SECURE_NO_WARNINGS 
#include "iostream"
using namespace std;
#include "string"
#include <vector>
#include <list>
#include "set"
#include <algorithm>
#include "functional"
#include "iterator"
#include <numeric>
#include "map"

//date:2019-07-07 10：20
//Author : null
//Project:STL案例_演讲比赛_搭建案例框架

class Speaker
{
public:
	string m_name;
	int m_score[3];
};

//产生选手
int GenSpeaker(map<int,Speaker> &mapSpeaker,vector<int> &v)
{
	return 0;
}

//选手抽签
int speech_contest_draw(vector<int> &v)
{
	return 0;
}

//选手比赛
int	speech_contest(int index,vector<int> &v1,map<int,Speaker> &mapSpeaker,vector<int> &v2)
{
	return 0;
}

//查看比赛结果
int	speech_contest_print(int index,vector<int> &v2,map<int,Speaker> &mapSpeaker)
{
	return 0;
}
int main()
{
	//容器设计
	map<int,Speaker> mapSpeaker;//所有参加比赛的选手
	vector<int> v1;//第一轮 演讲比赛 名单
	vector<int> v2;//第二轮 演讲比赛 名单
	vector<int> v3;//第三轮 演讲比赛 名单
	vector<int> v4;//最后前三名 演讲比赛 名单

	//产生选手 得到第一轮选手的比赛名单
	GenSpeaker(mapSpeaker,v1);

	//第一轮 选手抽签 选手比赛 查看比赛结果
	speech_contest_draw(v1);
	speech_contest(0,v1,mapSpeaker,v2);
	speech_contest_print(0,v2,mapSpeaker);

	//第二轮 选手抽签 选手比赛 查看比赛结果
	speech_contest_draw(v2);
	speech_contest(0,v2,mapSpeaker,v3);
	speech_contest_print(1,v3,mapSpeaker);

	//第三轮 选手抽签 选手比赛 查看比赛结果
	speech_contest_draw(v3);
	speech_contest(0,v3,mapSpeaker,v4);
	speech_contest_print(2,v4,mapSpeaker);
	
	cout<<"hellc"<<endl;
	system("pause");
	return 0;
}
	