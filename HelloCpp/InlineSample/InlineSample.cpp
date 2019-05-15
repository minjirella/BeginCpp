// InlineSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

#define AddDefine(a,b)((a) + (b))

int AddNormal(int a, int b)
{
	return a + b;
}

inline int AddInline(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 10, b = 2;

	cout << AddDefine(a, b) << endl;
	cout << AddNormal(a, b) << endl;
	cout << AddInline(a, b) << endl;

}

