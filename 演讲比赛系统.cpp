#include<iostream>
#include"speechManager.h"
using namespace std;
#include<string>
#include<ctime>
int main()
{
	//���������
	srand((unsigned int)time(NULL));
	speechManager sm;
	//���Դ������������ѡ��
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ�ţ�" << it->first << "������" << it->second.m_Name << "������" << it->second.m_Score[0] << endl;
	//}
	int choice = 0;
	
	while (true)
	{
		sm.showMenu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			sm.startSpeech();//��ʼ����
			break;
		case 2:
			sm.showRecord();//�鿴�����¼
			break;
		case 3:
			sm.clearFile();
			break;
		case 0:
			sm.exitSystem();//�˳�ϵͳ
			break;
		
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}