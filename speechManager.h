#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"Speaker.h"

class speechManager
{
public:
	//构造函数
	speechManager();
	//析构函数
	~speechManager();
	
	//初始化容器和属性
	void initSpeech();
	
	void showMenu();

	//退出系统
	void exitSystem();

	//一轮
	vector<int>v1;

	//一轮晋级
	vector<int>v2;

	//胜出前三名
	vector<int>vVictory;

	//存放编号和选手
	map<int, Speaker>m_Speaker;

	//创建12名选手
	void createSpeak();

	//整个流程控制函数
	void startSpeech();

	//抽签
	void drawSpeech();
	
	//比赛
	void speechcontest();

	//显示得分
	void showScore();

	//保存文件
	void saveRecord();

	//读取记录
	void loadRecord();

	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>>m_Record;

	//查看往届记录
	void showRecord();

	//清空文件记录
	void clearFile();



	int m_Index;
};
