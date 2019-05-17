// VirtualDestructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() { m_pszData = new char[32]; }
	~CMyData()
	{
		cout << "~CMyData()" << endl;
		delete m_pszData;
	}

private:
	char* m_pszData;
};

class CMyDataEx : public CMyData
{
public :
	CMyDataEx() { m_pnData = new int; }
	~CMyDataEx()
	{
		cout << "~CMyDataEx()" << endl;
		delete m_pnData;
	}

private:
	int *m_pnData;
};


int main()
{
	//����Ŭ������ ���� Ŭ���� ����
	CMyData* pData = new CMyDataEx;

	//CMyDataEx* pData = new CMyDataEx;

	//�������Ŀ� �´� �Ҹ��ڰ� ȣ��ȴ�.
	delete pData;

	return 0;
}
