#include "pch.h"
#include <iostream>
#include "car.h"
using namespace std;

Car::Car() {};
Car::Car(string name, int price, int efficiency, string color, string type, string gasType) 
{
	this->name = name;
	this->price = price;
	this->efficiency = efficiency;
	this->color = color;
	this->type = type;
	this->gasType = gasType;
};

void Car::setName(string name)
{
	this->name = name;
}

void Car::setPrice(int price)
{
	this->price = price;
}

void Car::setEfficiency(int efficiency)
{
	this->efficiency = efficiency;
}

void Car::setColor(string color)
{
	this->color = color;
}

void Car::setType(string Type)
{
	this->type = type;
}

void Car::setGasType(string gasType)
{
	this->gasType = gasType;
}

string Car::getName()
{
	return this->name;
}

int Car::getPrice()
{
	return this->price;
}

int Car::getEfficiency()
{
	return this->efficiency;
}

string Car::getColor()
{
	return this->color;
}

string Car::getType()
{
	return this->type;
}

string Car::getGasType()
{
	return this->gasType;
}

Car::~Car() {}