// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string fileName = "test.txt";
	ofstream writeFile(fileName.data());

	if (writeFile.is_open()) {
		writeFile << "Hello World!";
		writeFile.close();
	}

	ofstream output;
	output.open("log2.txt");
	output << "helo wald" << endl;
	output.close();

	cout << "Hello World!" << endl;
	return 0;
}

