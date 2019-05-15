#pragma once
#include <string>
using namespace std;

class Car
{
protected:
	string name;
	int price;
	int efficiency;
	string color;
	string type;
	string gasType;

public:
	Car();
	Car(string name, int price, int efficiency, string color, string type, string gasType);

	virtual ~Car();

	void setName(string name);
	void setPrice(int price);
	void setEfficiency(int efficiency);
	void setColor(string color);
	void setType(string type);
	void setGasType(string gasType);

	string getName();
	int getPrice();
	int getEfficiency();
	string getColor();
	string getType();
	string getGasType();
};