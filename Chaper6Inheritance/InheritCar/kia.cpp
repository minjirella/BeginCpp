#include "pch.h"
#include <iostream>
#include "kia.h"
using namespace std;

Kia::~Kia() {};

void Kia::repair(int resetEfficiency)
{
	if (getEfficiency() <= resetEfficiency)
	{
		setEfficiency(resetEfficiency);
		cout << "수리가 완료되었습니다" << endl;
	}
}