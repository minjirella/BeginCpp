// ClassNew.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class CTest
{
	int m_nData;

public:
	CTest()
	{
		cout << "CTest::CTest()" << endl;
	}

	~CTest()
	{
		cout << "~CTest::CTest()" << endl;
	}

};

int main()
{
	cout << "Begin" << endl;

	//new ������ ��� �������� ��ü ����
	CTest* pData = new CTest[3];
	//CTest* pData = new CTest;
	cout << "Test" << endl;

	//delete �����ڸ� �̿��� ��ü ����
	delete[]pData;
	//delete pData;
	//�迭�� �����ߴٸ� �迭�� �������ش�.
	cout << "End" << endl;


}

