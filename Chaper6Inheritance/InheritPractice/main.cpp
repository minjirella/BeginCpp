#include "pch.h"
#include <iostream>
#include "t_child.h"
using namespace std;

int main()
{
	T_Child a("kim","doctor");
	/*a.setName("kim");
	a.setValue("doctor"); */
	
	a.printName();
	a.printValue();
	return 0;
}