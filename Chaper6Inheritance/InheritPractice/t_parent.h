#include <string>
using namespace std;
#pragma once
class T_Parent
{
protected:
	string name;
	string value;

public:
	// �ƱԸ�Ʈ�� ���� �⺻ ������
	T_Parent();

	//name ���� �ƱԸ�Ʈ�� ������ ������
	T_Parent(string name, string value);

	//�Ҹ���
	virtual ~T_Parent();

	void setName(string name);
	void setValue(string value);

	string getName();
	string getValue();
};
