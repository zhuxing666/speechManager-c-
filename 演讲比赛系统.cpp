#include<iostream>
#include"speechManager.h"
using namespace std;
#include<string>
#include<ctime>
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	speechManager sm;
	//测试代码遍历创建的选手
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "选手编号：" << it->first << "姓名：" << it->second.m_Name << "分数：" << it->second.m_Score[0] << endl;
	//}
	int choice = 0;
	
	while (true)
	{
		sm.showMenu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			sm.startSpeech();//开始比赛
			break;
		case 2:
			sm.showRecord();//查看往届记录
			break;
		case 3:
			sm.clearFile();
			break;
		case 0:
			sm.exitSystem();//退出系统
			break;
		
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}