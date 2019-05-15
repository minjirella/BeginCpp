// Chaper6Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


//부모클래스
class CMyData
{
public:
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};


//파생클래스
class CMyDataEx : public CMyData
{
public:
	void SetData(int nParam)
	{
		if (nParam < 0)
			CMyData::SetData(0);

		if (nParam > 10)
			CMyData::SetData(10);
	}
};


int main()
{
	CMyData data;

	//부모클래스 접근
	data.SetData(-10);
	cout << data.GetData() << endl;

	//파생클래스에서 값을 보정한다
	CMyDataEx dataEx;
	dataEx.SetData(15);
	cout << dataEx.GetData() << endl;

	//MethodOver2
	CMyDataEx a;
	CMyData& rData = a;
	rData.SetData(15);
	cout << rData.GetData() << endl;

	return 0;
}

