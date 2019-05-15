// Chapter03Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class CTest
{
public:
	//CTest 클래스의 생성자 함수 선언 및 정의
	CTest()
	{
		//인스턴스가 생성되면 멤버 데이터를 자동으로 초기화한다.
		m_nData = 10;
	}

	int m_nData;

	//멤버함수 선언 및 정의
	void PrintData(void)
	{
		cout << m_nData << endl;
	}
};
int main()
{
	CTest t;
	t.PrintData();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
