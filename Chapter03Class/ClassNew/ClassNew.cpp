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

	//new 연산자 사용 동적으로 객체 생성
	CTest* pData = new CTest[3];
	//CTest* pData = new CTest;
	cout << "Test" << endl;

	//delete 연산자를 이용해 객체 삭제
	delete[]pData;
	//delete pData;
	//배열로 선언했다면 배열로 삭제해준다.
	cout << "End" << endl;


}

