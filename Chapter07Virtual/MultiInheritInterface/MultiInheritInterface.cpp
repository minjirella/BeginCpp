// MultiInheritInterface.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

class CMyUSB
{
public : 
	virtual int GetUsbVersion() = 0;
	virtual int GetTransferRate() = 0;
};

class CMySerial
{
	virtual int GetSignal() = 0;
	virtual int GetRate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial
{
	//USB 인터페이스 사용
	virtual int GetUsbVersion() { return 0; }
	virtual int GetTransferRate() { return 0; }

	//시리얼 인터페이스 사용
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int main()
{
	CMyDevice dev;

	return 0;
}


