#pragma once
#include <string>
#include "t_parent.h"
using namespace std;


class T_Child : public T_Parent
{
public:
	T_Child();
	T_Child(string name, string value);
	//using T_Parent::T_Parent; �������� ���, 
	//���� �ִ� �ΰ��� ������ using�� �ϳ��ν� �ս��� �����ִ�.

	virtual ~T_Child();

	void printName();
	void printValue();
};