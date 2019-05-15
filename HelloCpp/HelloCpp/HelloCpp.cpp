// HelloCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Car
{
private:
	unsigned int m_nSpeed;
	unsigned int m_nGear;
	string m_strType;
public:
	Car() {
		m_nGear = 1;
		m_nSpeed = 1;
		m_strType = "K3";
		cout << "생성" << endl;
	}
	~Car() {
		cout << "소멸" << endl;
	}
	void SetGear(unsigned int gear) { m_nGear = gear; }
	void SetSpeed(unsigned int speed) { m_nSpeed = speed; }
	void SetType(string type) { m_strType = type; }
	void speedUp() { m_nSpeed++; }
	void gearUp() { m_nSpeed++; }

	unsigned int getSpeed() { return m_nSpeed; }
	unsigned int getGear() { return m_nGear; }
	string getType() { return m_strType; }
};

int main(int argc, char* argv[])
{
	/*
	std::cout << 10 << std::endl;
	std::cout << 10U << std::endl;
	std::cout << 10.5F << std::endl;
	std::cout << 10.5 << std::endl;
	std::cout << 3+4 << std::endl;
	*/
	//int nAge;
	//std::cout << "나이를 입력하세요\n" << std::endl;
	//std::cin >> nAge;
	//
	//char szJob[32];
	//std::cout << "직업을 입력하세요\n" << std::endl;
	//std::cin >> szJob;
	//
	//std::string strName;
	//std::cout << "이름을 입력하세요\n" << std::endl;
	//std::cin >> strName;
	//
	//std::cout << "당신의 이름은 " << strName << "이고, 나이는 " 
	//	<< nAge << "살이며, 직업은 " << szJob << "입니다." << std::endl;
	
	/*int a = 10;
	int b(a);
	auto c(b);
	std::cout << a + b + c << std::endl;
*/
	/*int *pData = new int;
	int* pNewData = new int(10);

	*pData = 5;
	std::cout << *pData << std::endl;
	std::cout << *pNewData << std::endl;

	delete pData;
	delete pNewData;

	return 0;*/

		
	Car car1;
	cout << car1.getType() << endl;
	delete car1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
