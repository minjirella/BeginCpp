#include "pch.h"
#include <iostream>
#include "kia.h"
#include "BMW.h"
using namespace std;

int main()
{
	Kia kia("k3", 3000, 11, "red", "준중형", "LPG");

	cout << kia.getName() << " "
		<< kia.getPrice() << " "
		<< kia.getEfficiency() << endl;

	kia.repair();
	cout << kia.getName() << " "
		<< kia.getPrice() << " "
		<< kia.getEfficiency() << endl;

	BMW bmw("E90", 8000, 22, "black", "대형", "가솔린");
	BMW bmw2("E10", 500, 22, "red", "소형", "가솔린");

	bmw.giftEvent();
	bmw2.giftEvent();
	
	cout << bmw.getName() << " "
		<< bmw.getPrice() << " "
		<< bmw.getBlackBox() << endl;
	
	cout << bmw2.getName() << " "
		<< bmw2.getPrice() << " "
		<< bmw2.getBlackBox() << endl;

}
