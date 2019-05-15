// Chaper6Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


//�θ�Ŭ����
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


//�Ļ�Ŭ����
class CMyDataEx : public CMyData
{
public:
	CMyDataEx() { cout << "CMyDataEx()" << endl; }
	void TestFunc()
	{
		//�⺻���� ����� ����
		PrintData();
		SetData(5);
		cout << CMyData::GetData() << endl;
	}
};


int main()
{
	CMyDataEx data;

	//�θ�Ŭ���� ����
	data.SetData(10);
	cout << data.GetData() << endl;

	//�Ļ�Ŭ���� ����� ����
	data.TestFunc();

	//cout << CMyData::PrintData() << endl; -> protected�� �ִ� ���̶� ���������� �Ұ��ϴ�.
	return 0;
}

