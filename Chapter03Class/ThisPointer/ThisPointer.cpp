// ThisPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam) : m_nData(nParam) {};
	void PrintData()
	{
		cout << m_nData << endl;
		cout << CMyData::m_nData << endl;
		cout << this->m_nData << endl;
		cout << this->CMyData::m_nData << endl;


	}
private :
	int m_nData;
};

int main()
{
	CMyData a(5), b(10);
	a.PrintData();
	b.PrintData();
}