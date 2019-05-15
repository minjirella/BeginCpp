#include "pch.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	virtual void PrintData()
	{
		cout << "CMyData: " << m_nData << endl;
	}

	void TestFunc()
	{
		cout << "***TestFunc()***" << endl;
		PrintData();
		cout << "****************" << endl;
	}

protected:
	int m_nData = 10;
};

class CMyDataEx : public CMyData
{
public:
	virtual void PrintData()
	{
		cout << "CMyDataEx: " << m_nData * 2 << endl;
	}
};

int main()
{
	CMyDataEx a;
	a.PrintData();

	CMyData& b = a;

	b.PrintData();

	a.TestFunc();

	int aList[5] = { 10,20,30,40,50 };
	for (auto& i : aList)
		cout << i << ' ';
	cout << endl;

	return 0;
}
