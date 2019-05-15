#include "pch.h"
#include <iostream>
#include "BMW.h"
using namespace std;

BMW::~BMW() {};

BMW::BMW(string name, int price, string type, string blackBox)
{
	this->name = name;
	this->price = price;
	this->type = type;
	this->blackBox = blackBox;
}

void BMW::setBlackBox(string blackBox)
{
	this->blackBox = blackBox;
}

string BMW::getBlackBox()
{
	return this->blackBox;
}

void BMW::giftEvent()
{
	if (getType() == "준중형" || getPrice() >= 1000) {
		cout << getName() << "같은 호갱은 블랙박스 가지라구" << endl;
		setBlackBox("아이나비");
	}
}