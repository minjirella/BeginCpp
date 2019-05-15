#include "pch.h"
#include <iostream>
#include "t_child.h"
using namespace std;

T_Child::T_Child() {};

T_Child::T_Child(string name, string value):T_Parent(name, value)
{
	/*this->name = name;
	this->value = value;
	이러면 코드재사용이에유*/
}

T_Child::~T_Child() {};

void T_Child::printName()
{
	cout << getName() << endl;
}

void T_Child::printValue()
{
	cout << getValue() << endl;
}