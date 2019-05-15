// Chaper6Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


//부모클래스
class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

protected:
	void PrintData() { cout << "CMyData::PrintData()" << endl; }

private:
	int m_nData = 0;
};


//파생클래스
class CMyDataEx : public CMyData
{
public:
	CMyDataEx() { cout << "CMyDataEx()" << endl; }
	void TestFunc()
	{
		//기본형식 멤버에 접근
		PrintData();
		SetData(5);
		cout << CMyData::GetData() << endl;
	}
};


int main()
{
	CMyDataEx data;

	//부모클래스 접근
	data.SetData(10);
	cout << data.GetData() << endl;

	//파생클래스 멤버에 접근
	data.TestFunc();

	//cout << CMyData::PrintData() << endl; -> protected에 있는 것이라 직접접근이 불가하다.
	return 0;
}

