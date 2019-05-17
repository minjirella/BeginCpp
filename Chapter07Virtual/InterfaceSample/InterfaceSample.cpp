// InterfaceSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class CMyObject
{
public:
	CMyObject() {}
	virtual ~CMyObject() {}

	//모든파생클래스는 이 메서드를 가졌다고 가정한다.
	virtual int GetDeviceID() = 0;

protected:
	int m_nDeviceID;
};

void PrintID(CMyObject* pObj)
{
	//실제로 어떤 것일지는 모르나, ID는 출력가능하다.
	cout << "Device ID : " << pObj->GetDeviceID() << endl;
}

class CMyTV : public CMyObject
{
public:
	CMyTV(int nID) { m_nDeviceID = nID; }
	virtual int GetDeviceID()
	{
		cout << "CMyTv::GetDeviceID()" << endl;
		return m_nDeviceID;
	}
};

class CMyPhone : public CMyObject
{
public:
	CMyPhone(int nID) { m_nDeviceID = nID; }
	virtual int GetDeviceID()
	{
		cout << "CMyPhone::GetDeviceID()" << endl;
		return m_nDeviceID;
	}
};

int main()
{
	CMyTV a(5);
	CMyPhone b(10);

	//실제 객체가 무엇이든 알아서 자신의 ID를 출력한다.
	::PrintID(&a);
	::PrintID(&b);

	return 0;
}
