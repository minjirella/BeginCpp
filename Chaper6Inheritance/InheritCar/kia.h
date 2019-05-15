#pragma once
#include <string>
#include "car.h"
#include <iostream>


class Kia : public Car
{

public:
	using Car::Car;

	virtual ~Kia();
	
	//설정 : 기아차는 수리를 받으면 연비가 늘어나.
	void repair(int resetEfficiency = 100);

};