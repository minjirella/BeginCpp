#include <string>
using namespace std;
#pragma once
class T_Parent
{
protected:
	string name;
	string value;

public:
	// 아규먼트가 없는 기본 생성자
	T_Parent();

	//name 값을 아규먼트로 가지는 생성자
	T_Parent(string name, string value);

	//소멸자
	virtual ~T_Parent();

	void setName(string name);
	void setValue(string value);

	string getName();
	string getValue();
};
