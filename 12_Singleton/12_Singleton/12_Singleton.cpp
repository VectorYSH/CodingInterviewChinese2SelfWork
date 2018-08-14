// 12_Singleton.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstring>
#include<cstdio>

//����ʵ��(���̰߳�ȫ)
//����������˼�壬�����򲻵��ѾͲ���ȥʵ�����࣬
//Ҳ����˵�ڵ�һ���õ���ʵ����ʱ��Ż�ȥʵ������

//class Singleton
//{
//public:
//	static Singleton* getInstance();
//protected:
//	Singleton(){}
//private:
//	static Singleton *p;
//};
//
//Singleton* Singleton::p = NULL;
//Singleton* Singleton::getInstance()
//{
//	if (NULL == p)
//		p = new Singleton();
//	return p;
//}
//
////1.����ʵ���̰߳�ȫ������ģʽ
//class Singleton
//{
//public:
//	static pthread_mutex_t mutex;
//	static Singleton* getInstance();
//protected:
//	Singleton()
//	{
//		pthread_mutex_init(&mutex);
//	}
//private:
//	static Singleton* p;
//};
//
//pthread_mutex_t Singleton::mutex;
//Singleton* Singleton::p = NULL;
//Singleton* Singleton::getInstance()
//{
//	if (NULL == p)
//	{
//		pthread_mutex_lock(&mutex);
//		if (NULL == p)
//			p = new Singleton();
//		pthread_mutex_unlock(&mutex);
//	}
//	return p;
//}
//
////2.�ڲ���̬����ʵ������ģʽ
//class Singleton
//{
//public:
//	static pthread_mutex_t mutex;
//	static Singleton* getInstance();
//protected:
//	Singleton()
//	{
//		pthread_mutex_init(&mutex);
//	}
//};
//
//pthread_mutex_t Singleton::mutex;
//Singleton* Singleton::getInstance()
//{
//	pthread_mutex_lock(&mutex);
//	static singleton obj;
//	pthread_mutex_unlock(&mutex);
//	return &obj;
//}
//
//


#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
class Singleton
{
private:
	Singleton(){}
	static Singleton* singel;
public:

	static Singleton* GetInstance()
	{
		if (singel == NULL)
		{
			singel = new Singleton();
		}
		return singel;
	}

	/*����ģʽ��򵥵İ汾*/
	static Singleton *GetInstance(int temp)
	{
		if (m_Instance == NULL)
		{
			m_Instance = new Singleton(temp);
		}
		return m_Instance;
	}

	static void DestoryInstance()
	{
		if (m_Instance != NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}

	// ���������Ա������ֵ
	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton(int temp){ m_Test = temp; }
	static Singleton *m_Instance;
	int m_Test;

};

struct print
{
	static int a;
	print()
	{
		/*printf("��d\n"��print::a);*/
		cout << a << endl;
		a++;
	}
};

int print::a= 1;

Singleton* Singleton::singel = NULL; //ע�⾲̬���������ʼ��

Singleton *Singleton::m_Instance = NULL;

int _tmain(int argc, _TCHAR* argv[])
{
	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();
	if (s1 == s2)
	{
		cout<<"OK"<<endl;
	} 
	else
	{
		cout<<"no"<<endl;
	}

	/*����ģʽ��򵥵İ汾*/
	Singleton *singletonObj = Singleton::GetInstance(10);
	Singleton *singletonObj2 = Singleton::GetInstance(11);
	cout << singletonObj->GetTest() << endl;//�����10
	cout << singletonObj2->GetTest() << endl;//���ǻ����10������ģʽ�£��Ѿ�ʵ�������Ͳ�����ʵ����
	Singleton::DestoryInstance();

	 print tt[10];
	return 0;
}

