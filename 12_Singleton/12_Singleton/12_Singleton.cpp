// 12_Singleton.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstring>
#include<cstdio>

//经典实现(非线程安全)
//懒汉：故名思义，不到万不得已就不会去实例化类，
//也就是说在第一次用到类实例的时候才会去实例化，

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
////1.加锁实现线程安全的懒汉模式
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
////2.内部静态变量实现懒汉模式
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

	/*单例模式最简单的版本*/
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

	// 测试输出成员变量的值
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
		/*printf("％d\n"，print::a);*/
		cout << a << endl;
		a++;
	}
};

int print::a= 1;

Singleton* Singleton::singel = NULL; //注意静态变量类外初始化

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

	/*单例模式最简单的版本*/
	Singleton *singletonObj = Singleton::GetInstance(10);
	Singleton *singletonObj2 = Singleton::GetInstance(11);
	cout << singletonObj->GetTest() << endl;//会输出10
	cout << singletonObj2->GetTest() << endl;//还是会输出10，单例模式下，已经实例化过就不能再实例化
	Singleton::DestoryInstance();

	 print tt[10];
	return 0;
}

