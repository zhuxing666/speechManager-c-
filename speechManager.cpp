#include"speechManager.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>

//���캯��
speechManager::speechManager()
{
	//��ʼ������������
	this->initSpeech();

	//���ô���12��ѡ�ֹ��캯��
	this->createSpeak();

	//���������¼
	this->loadRecord();
}


void speechManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


//�˳�ϵͳ
void speechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	system("cls");
	exit(0);
}


//��ʼ������������
void speechManager::initSpeech()
{

	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//��ʼ����������
	this->m_Index = 1;

	//����¼������� Ҳ���
	this->m_Record.clear();
}


//����12��ѡ��
void speechManager::createSpeak()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		
		Speaker sp;

		sp.m_Name = name;


		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//����ѡ�ֱ�ŷ���V1
		this->v1.push_back(i + 10001);
		//ѡ�ֱ�ź�ѡ�ַ���MAP

		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}
}





//�������̿��ƺ���
void speechManager::startSpeech()
{
	//һ�ֱ���

	//1����ǩ

	this->drawSpeech();   //���ú���

	//2������
	this->speechcontest();

	//3����ʾ����
	this->showScore();

	//���ֱ���

	//1����ǩ
	this->m_Index++;
	this->drawSpeech();

	//2������
	this->speechcontest();

	//3����ʾ���ս��
	this->showScore();

	//4�����������������
	this->saveRecord();
	//���ñ�������ȡ��¼
	//��ʼ������������
	this->initSpeech();

	//���ô���12��ѡ�ֹ��캯��
	this->createSpeak();

	//���������¼
	this->loadRecord();

	cout << "�����������" << endl;
	system("pause");
	system("cls");
}


//��ǩ
void speechManager::drawSpeech()
{
	cout << "��<<" << this->m_Index << ">>�ֱ������ڳ�ǩ" << endl;
	cout << "-----------------------------" << endl;
	cout << "��ǩ����ݽ�˳�����£�" << endl;

	if (this->m_Index==1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << "   ";

		}
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());


		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << "   ";

		}
		cout << endl;
	}

	cout << "---------------------" << endl;
	system("pause");

}


//����
void speechManager::speechcontest()
{
	cout << "--------��" << this->m_Index << "�ֱ�����ʽ��ʼ--------" << endl;


	//׼����ʱ���� ���С��ɼ�
	multimap<double, int, greater<double>>groupScore;

	int num = 0;//ͳ����Ա����6��һ��

	vector<int>v_Src;//����ѡ������
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//��������ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600 )/ 10.f;//ע����������ȼ�
			//cout << score << "  ";
			d.push_back(score);
		}
	/*	cout << endl;*/
		sort(d.begin(), d.end(), greater<double>());//��������

		d.pop_front();//ȥ����߷�
		d.pop_back();//ȥ����ͷ�


	   //�ۼ��ܷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();//ƽ����
		//��ӡƷ����
		//cout << "��ţ� " << *it << "  ������" << this->m_Speaker[*it].m_Name << " ��ȡƽ���֣�   " << avg << endl;

		//ƽ���ַ���map
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//��ַ�����ʱС������
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷�Value�Ǳ��
		//ȡ��ÿ6��ǰ��
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���:" << it->second << "������" << this->m_Speaker[it->second].m_Name << "�ɼ���"
					<< this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}

			}


			groupScore.clear();//С���������
			cout << endl;

				
		}
	}
	cout << "��" << this->m_Index << "�ֱ������" << endl;
		system("pause");
}


//��ʾ�÷�
void speechManager::showScore()
{
	cout << "------------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-------------" << endl;


	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}


	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ� " << *it << "������ " << this->m_Speaker[*it].m_Name << "�÷֣� " <<
			this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();

}


//�����ļ�
void speechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios:: app);//��׷�ӷ�ʽд�ļ�

	//��ÿ��ѡ������ д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	//�����ļ���Ϊ��״̬
	this->fileIsEmpty = false;

}

//��ȡ��¼
void speechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);//���ļ�


	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;

	}

	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);//�������ȡ�ĵ����ַ� �Ż���
	string  data;
	int index = 0;//�ڼ������
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>v;//��ż�¼����
		int pos = -1;//�鵽������λ�õı���

		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//û���ҵ����
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
	
		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();

	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	//{
	//	cout << it->first << "�ھ���ţ� " << it->second[0] << "������ " << it->second[1] << endl;
	//}

}


//�鿴�����¼
void speechManager::showRecord()
{
	
		if (this->fileIsEmpty)
		{
			cout << "�ļ�Ϊ�ջ����ļ������ڣ�" << endl;
		}
		else 
		{
			for (int i=0; i < this->m_Record.size(); i++)
			{
				cout << "��" << i + 1 << "��"
					<< "�ھ���ţ�" << this->m_Record[i][0] << "�÷֣� " << this->m_Record[i][1] << "  "
					<< "�Ǿ���ţ�" << this->m_Record[i][2] << "�÷֣� " << this->m_Record[i][3] << "  "
					<< "������ţ�" << this->m_Record[i][4] << "�÷֣� " << this->m_Record[i][5] << endl;
			}
		}
		

	
	system("pause");
	system("cls");
}


//����ļ���¼
void speechManager::clearFile()
{
	cout << "���Ƿ�ȷ������ļ���" << endl;
	cout << "1����" << endl;
	cout << "2����" << endl;
	int select = 0;
	cin >> select;
	
	if (select == 1)
	{
		//ȷ�����
		ofstream ofs("speech.csv", ios::trunc);//ɾ�����´������ļ�
		ofs.close();

		//��ʼ������������
		this->initSpeech();

		//���ô���12��ѡ�ֹ��캯��
		this->createSpeak();

		//���������¼
		this->loadRecord();


		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");

}



//��������
speechManager::~speechManager()
{

}

