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
		cout << "������ �Ϸ�Ǿ����ϴ�" << endl;
	}
}