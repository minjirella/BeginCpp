// InheritPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "t_parent.h"
using namespace std;

T_Parent::T_Parent()
{
	
}
T_Parent::T_Parent(string name, string value)
{
	this->name = name;
	this->value = value;
}

void T_Parent::setName(string name)
{
	this->name = name;
}
void T_Parent::setValue(string value)
{
	this->value = value;
}

string T_Parent::getName()
{
	return this->name;
}

string T_Parent::getValue()
{
	return this->value;
}

//소멸자를 꼭 넣어주어야한다.
T_Parent::~T_Parent() {}