#pragma once
#include <string>
#include "t_parent.h"
using namespace std;


class T_Child : public T_Parent
{
public:
	T_Child();
	T_Child(string name, string value);
	//using T_Parent::T_Parent; 생성자의 상속, 
	//위에 있는 두개의 구문을 using문 하나로써 손쉽게 쓸수있다.

	virtual ~T_Child();

	void printName();
	void printValue();
};