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

// 현재시간을 string type으로 return하는 함수
const string currentDateTime() {
	time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y_%m_%d_%H_%M_%S", &tstruct); 
	//yyyy_mm_dd_hh_mm_ss 이라는 string 값을 받아옵니다.
	return buf;
}

//-----파일 생성 LOG저장-----
// TODO : 하나의 메소드 생성/콘솔로 나오는 모든 로그를 파일로 export
string fileName = currentDateTime() + ".log";
ofstream outFile(fileName);

void __cdecl RecvThread (void * p)
{
	SOCKET sock = (SOCKET)p;
	char buf[256];

	while(1)
	{
		//-----------클라이언트로부터 수신------------
		int recvsize = recv(sock,buf,sizeof(buf),0);
		if(recvsize <= 0)		break;
		//------------------------------------------------
		buf[recvsize] = '\0';
		cout << buf << endl; //모니터 출력
		outFile << buf << endl; // 파일로 대화로그 저장
		//----------클라이언트에게 전송------------------
		for(int i = 0 ; i < clnt_list.size(); i++)
		{
			if(clnt_list[i] != sock)
			{
				int sendsize = send(clnt_list[i],buf,strlen(buf),0);
			}
		}
		//-----------------------------------------------
	}
	cout << "접속 종료\n" << endl;
	outFile << "접속 종료\n" << endl;
	
	//------------vector에 있는 데이터 지우기-----------
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

	//------------소켓 해제---------------------
	closesocket(sock);
	//----------------------------------------
}

int main()
{
	//-------소켓 라이브러리 불러오기--------
	WSADATA wsaData;
	int retval = WSAStartup(MAKEWORD(2,2),&wsaData);
	if(retval != 0)
	{
		printf("WSAStartup() Error\n");
		outFile << "WSAStartup() Error\n" << endl;

		return 0;
	}
	//-------------------------------------------

	//----------소켓 생성--------------
	SOCKET serv_sock;
	serv_sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(serv_sock == SOCKET_ERROR)
	{
		printf("socket() Error\n");
		outFile << "socket() Error\n" << endl;
		return 0;
	}
	//-----------------------------------

	//--------서버(자신)의 소켓 정보 입력------------
	SOCKADDR_IN serv_addr = {0};					// 초기화
	serv_addr.sin_family = AF_INET;					// IP 사용
	serv_addr.sin_port = htons(8889);				// 포트 8889번
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);	// 주소는 알아서 찾기
	//------------------------------------------------

	//-----------인터넷에 연결---------------------
	retval = bind(serv_sock,(SOCKADDR*)&serv_addr,sizeof(SOCKADDR));
	if(retval == SOCKET_ERROR)
	{
		printf("bind() Error\n");
		outFile << "bind() Error\n" << endl;
		return 0;
	}
	//--------------------------------------------

	//-----------대기인원 설정-----------------
	listen(serv_sock,5);		// 5명까지만 대기할 수 있게 함...
	//-------------------------------------------
	SOCKADDR_IN clnt_addr = {0};
	int size = sizeof(SOCKADDR_IN);
	
	while(1)
	{
		//-------------클라이언트 접속 대기, connect를 하면 리턴함-------------
		SOCKET clnt_sock = accept(serv_sock,(SOCKADDR*)&clnt_addr,&size);
		if(clnt_sock == SOCKET_ERROR)
		{
			printf("accept() Error\n");
			outFile << "accept() Error\n" << endl;
			continue;
		}
		//----------------------------------------------------------------------

		//----------------vector 에 데이터 넣기------------
		clnt_list.push_back(clnt_sock);
		//--------------------------------------------------

		printf("클라이언트 접속\n");
		outFile << "클라이언트 접속" << endl;

		printf("IP : %s, Port : %d\n",inet_ntoa(clnt_addr.sin_addr),clnt_addr.sin_port);
		outFile << "IP : "<< inet_ntoa(clnt_addr.sin_addr) << " Port : "<< clnt_addr.sin_port << endl;
		//-----------수신 스레드 생성-------------
		_beginthread(RecvThread,NULL,(void*)clnt_sock);
	}
	//----------소켓 닫음---------------
	closesocket(serv_sock);

	//---라이브러리 해제 / 파일 close----
	outFile.close();
	WSACleanup();
}