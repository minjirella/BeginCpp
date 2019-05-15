#pragma once
#include <string>
#include "car.h"

class BMW :public Car
{
private:
	string blackBox;

public:
	using Car::Car;
	virtual ~BMW();

	BMW(string name, int price, string type, string blackBox);

	void setBlackBox(string blackBox);

	string getBlackBox();

	void giftEvent();
};