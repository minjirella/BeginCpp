#pragma comment (lib, "ws2_32.lib")
#include <stdio.h>
#include <WinSock2.h>
#include <process.h>
#pragma warning(disable:4996)


void __cdecl RecvThread (void * p)
{
	SOCKET sock = (SOCKET)p;
	char buf[256];
	while(1)
	{
		//-----------서버로부터 수신------------
		int recvsize = recv(sock,buf,sizeof(buf),0);
		if(recvsize <= 0)
		{
			printf("서버가 종료되었습니다\n");
			break;
		}
		//------------------------------------------------
		buf[recvsize] = '\0';
		printf("\r%s\n>>",buf);
	}
}

int main()
{
	//-------소켓 라이브러리 불러오기(?)--------
	WSADATA wsaData;
	int retval = WSAStartup(MAKEWORD(2,2),&wsaData);
	if(retval != 0)
	{
		printf("WSAStartup() Error\n");
		return 0;
	}
	//------------------------------------------

	//---------소켓생성-------- 
	SOCKET serv_sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);	//TCP를 이용한 소켓
	//-------------------------

	//---------서버 정보 입력--------------------
	SOCKADDR_IN serv_addr;
	serv_addr.sin_family = AF_INET;						// IP주소를 이용하고
	serv_addr.sin_port = htons(8889);					// 소켓은 8889번에
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");	// 서버의 ip 주소는 serverIP입력
	//--------------------------------------------

	//---------서버 연결------------
	retval = connect(serv_sock,(SOCKADDR*)&serv_addr,sizeof(SOCKADDR));
	if(retval == SOCKET_ERROR)
	{
		printf("connect() Error\n");
		return 0;
	}
	//-------------------------------

	char nick[20];
	printf("닉네임 >> ");
	gets_s(nick);

	_beginthread(RecvThread,0,(void*)serv_sock);

	while(1)
	{
		char buf[256] = {0};
		char str[256];
		printf(">> ");
		gets_s(str);
		sprintf(buf,"[%s] %s",nick,str);

		//---------서버에 메시지 전송---------------
		int sendsize = send(serv_sock,buf,strlen(buf),0);
		if(sendsize <= 0)
			break;
		//------------------------------------------
	}

	//----------소켓 닫음------------------
	closesocket(serv_sock);
	//-------------------------------------

	//---------라이브러리 해제(?)---------
	WSACleanup();
	//-------------------------------------
}