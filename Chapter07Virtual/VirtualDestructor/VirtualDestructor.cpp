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
	//상위클래스로 하위 클래스 참조
	CMyData* pData = new CMyDataEx;

	//CMyDataEx* pData = new CMyDataEx;

	//참조형식에 맞는 소멸자가 호출된다.
	delete pData;

	return 0;
}
