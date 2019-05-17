// AdtSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
#define DEFAULT_FARE 1000
class CPerson
{
public:
	CPerson() {}
	virtual ~CPerson()
	{
		cout << "virtual ~CPerson()" << endl;
	}

	virtual void CalcFare() = 0;

	virtual unsigned int GetFare() { return m_nFare; }

protected:
	unsigned int m_nFare = 0;
};

class CBaby : public CPerson
{
	//0%
public:
	virtual void CalcFare()
	{
		m_nFare = 0;
	}
};

class Child : public CPerson
{
	//50%
public:
	virtual void CalcFare()
	{
		m_nFare = DEFAULT_FARE * 50 / 100;
	}
};

class CTeen : public CPerson
{
	//75%
public:
	virtual void CalcFare()
	{
		m_nFare = DEFAULT_FARE * 75 / 100;
	}
};

class CAdult : public CPerson
{
	//100%
public:
	virtual void CalcFare()
	{
		m_nFare = DEFAULT_FARE;
	}
};
int main()
{
	CPerson* arList[3] = { 0 };
	int nAge = 0;

	for (auto& person : arList)
	{
		cout << "���̸� �Է��ϼ���: ";
		cin >> nAge;
		if (nAge < 8)
			person = new CBaby;
		else if (nAge < 14)
			person = new Child;
		else if (nAge < 20)
			person = new CTeen;
		else
			person = new CAdult;


		person->CalcFare();
	}

	//�ڷ����
	for (auto person : arList)
		cout << person->GetFare() << "��" << endl;
	//�ڷ���� ����
	for (auto person : arList)
		delete person;

	return 0;
}
