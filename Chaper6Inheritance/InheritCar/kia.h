#pragma once
#include <string>
#include "car.h"
#include <iostream>


class Kia : public Car
{

public:
	using Car::Car;

	virtual ~Kia();
	
	//���� : ������� ������ ������ ���� �þ.
	void repair(int resetEfficiency = 100);

};