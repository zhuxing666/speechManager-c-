#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"Speaker.h"

class speechManager
{
public:
	//���캯��
	speechManager();
	//��������
	~speechManager();
	
	//��ʼ������������
	void initSpeech();
	
	void showMenu();

	//�˳�ϵͳ
	void exitSystem();

	//һ��
	vector<int>v1;

	//һ�ֽ���
	vector<int>v2;

	//ʤ��ǰ����
	vector<int>vVictory;

	//��ű�ź�ѡ��
	map<int, Speaker>m_Speaker;

	//����12��ѡ��
	void createSpeak();

	//�������̿��ƺ���
	void startSpeech();

	//��ǩ
	void drawSpeech();
	
	//����
	void speechcontest();

	//��ʾ�÷�
	void showScore();

	//�����ļ�
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>>m_Record;

	//�鿴�����¼
	void showRecord();

	//����ļ���¼
	void clearFile();



	int m_Index;
};
