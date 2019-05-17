// Chapter8Friends.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;

class CNode
{
	//friend Ŭ���� ����
	friend class CMyList;

public:
	explicit CNode(const char* pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	//���� ���Ḯ��Ʈ�� ������ ������
	char m_szName[32];
	CNode* pNext = nullptr;
};

class CMyList
{
public:
	CMyList() : m_HeadNode("DummyHead") {}
	~CMyList()
	{
		//����Ʈ�� ��� �����͵��� ��� ����ϰ� ����
		CNode* pNode = m_HeadNode.pNext;
		CNode* pDelete = nullptr;

		while (pNode)
		{
			pDelete = pNode;
			pNode = pNode -> pNext;

			cout << pDelete->m_szName << endl;
			delete pDelete;
		}

		m_HeadNode.pNext = nullptr;
	}

	void AddNewNode(const char* pszName)
	{
		CNode* pNode = new CNode(pszName);

		//����Ʈ�� ���ο� ��带 �߰�
		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

private:
	CNode m_HeadNode;
};

int main()
{
	CMyList list;
	list.AddNewNode("�浿");
	list.AddNewNode("�浿");
	list.AddNewNode("�浿");
}
