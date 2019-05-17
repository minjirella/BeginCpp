#define _CRT_SECURE_NO_WARNINGS
#pragma comment (lib , "ws2_32.lib")
#pragma warning(disable:4996)
#include <stdio.h>
#include <WinSock2.h>
#include <process.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

vector<SOCKET> clnt_list;

// ����ð��� string type���� return�ϴ� �Լ�
const string currentDateTime() {
	time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y_%m_%d_%H_%M_%S", &tstruct); 
	//yyyy_mm_dd_hh_mm_ss �̶�� string ���� �޾ƿɴϴ�.
	return buf;
}

//-----���� ���� LOG����-----
// TODO : �ϳ��� �޼ҵ� ����/�ַܼ� ������ ��� �α׸� ���Ϸ� export
string fileName = currentDateTime() + ".log";
ofstream outFile(fileName);

void __cdecl RecvThread (void * p)
{
	SOCKET sock = (SOCKET)p;
	char buf[256];

	while(1)
	{
		//-----------Ŭ���̾�Ʈ�κ��� ����------------
		int recvsize = recv(sock,buf,sizeof(buf),0);
		if(recvsize <= 0)		break;
		//------------------------------------------------
		buf[recvsize] = '\0';
		cout << buf << endl; //����� ���
		outFile << buf << endl; // ���Ϸ� ��ȭ�α� ����
		//----------Ŭ���̾�Ʈ���� ����------------------
		for(int i = 0 ; i < clnt_list.size(); i++)
		{
			if(clnt_list[i] != sock)
			{
				int sendsize = send(clnt_list[i],buf,strlen(buf),0);
			}
		}
		//-----------------------------------------------
	}
	cout << "���� ����\n" << endl;
	outFile << "���� ����\n" << endl;
	
	//------------vector�� �ִ� ������ �����-----------
	vector<SOCKET>::iterator iter = clnt_list.begin();
	for(int i = 0 ; i < clnt_list.size() ; i++)
	{
		if(clnt_list[i] == sock)
		{
			clnt_list.erase(iter);
			break;
		}
		iter++;
	}
	//---------------------------------------------------

	//------------���� ����---------------------
	closesocket(sock);
	//----------------------------------------
}

int main()
{
	//-------���� ���̺귯�� �ҷ�����--------
	WSADATA wsaData;
	int retval = WSAStartup(MAKEWORD(2,2),&wsaData);
	if(retval != 0)
	{
		printf("WSAStartup() Error\n");
		outFile << "WSAStartup() Error\n" << endl;

		return 0;
	}
	//-------------------------------------------

	//----------���� ����--------------
	SOCKET serv_sock;
	serv_sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(serv_sock == SOCKET_ERROR)
	{
		printf("socket() Error\n");
		outFile << "socket() Error\n" << endl;
		return 0;
	}
	//-----------------------------------

	//--------����(�ڽ�)�� ���� ���� �Է�------------
	SOCKADDR_IN serv_addr = {0};					// �ʱ�ȭ
	serv_addr.sin_family = AF_INET;					// IP ���
	serv_addr.sin_port = htons(8889);				// ��Ʈ 8889��
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);	// �ּҴ� �˾Ƽ� ã��
	//------------------------------------------------

	//-----------���ͳݿ� ����---------------------
	retval = bind(serv_sock,(SOCKADDR*)&serv_addr,sizeof(SOCKADDR));
	if(retval == SOCKET_ERROR)
	{
		printf("bind() Error\n");
		outFile << "bind() Error\n" << endl;
		return 0;
	}
	//--------------------------------------------

	//-----------����ο� ����-----------------
	listen(serv_sock,5);		// 5������� ����� �� �ְ� ��...
	//-------------------------------------------
	SOCKADDR_IN clnt_addr = {0};
	int size = sizeof(SOCKADDR_IN);
	
	while(1)
	{
		//-------------Ŭ���̾�Ʈ ���� ���, connect�� �ϸ� ������-------------
		SOCKET clnt_sock = accept(serv_sock,(SOCKADDR*)&clnt_addr,&size);
		if(clnt_sock == SOCKET_ERROR)
		{
			printf("accept() Error\n");
			outFile << "accept() Error\n" << endl;
			continue;
		}
		//----------------------------------------------------------------------

		//----------------vector �� ������ �ֱ�------------
		clnt_list.push_back(clnt_sock);
		//--------------------------------------------------

		printf("Ŭ���̾�Ʈ ����\n");
		outFile << "Ŭ���̾�Ʈ ����" << endl;

		printf("IP : %s, Port : %d\n",inet_ntoa(clnt_addr.sin_addr),clnt_addr.sin_port);
		outFile << "IP : "<< inet_ntoa(clnt_addr.sin_addr) << " Port : "<< clnt_addr.sin_port << endl;
		//-----------���� ������ ����-------------
		_beginthread(RecvThread,NULL,(void*)clnt_sock);
	}
	//----------���� ����---------------
	closesocket(serv_sock);

	//---���̺귯�� ���� / ���� close----
	outFile.close();
	WSACleanup();
}