// Chaper6Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


//�θ�Ŭ����
class CMyData
{
public:
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};


//�Ļ�Ŭ����
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

	//�θ�Ŭ���� ����
	data.SetData(-10);
	cout << data.GetData() << endl;

	//�Ļ�Ŭ�������� ���� �����Ѵ�
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

