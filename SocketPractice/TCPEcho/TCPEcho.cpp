// TCPEcho.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define PORT_NUM      10200
#define BLOG_SIZE       5
#define MAX_MSG_LEN 256

#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32")
#pragma warning(disable:4996)
SOCKET SetTCPServer(short pnum, int blog);//대기 소켓 설정
void AcceptLoop(SOCKET sock);//Accept Loop
void DoIt(SOCKET dosock); //송수신

int main()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	SOCKET sock = SetTCPServer(PORT_NUM, BLOG_SIZE);//대기 소켓 설정
	if (sock == -1)
	{
		perror("대기 소켓 오류");
		WSACleanup();
		return 0;
	}
	AcceptLoop(sock);//Accept Loop
	WSACleanup();//윈속 해제화
	return 0;
}

SOCKET SetTCPServer(short pnum, int blog)
{
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//소켓 생성
	if (sock == -1)
		return -1;

	//소켓 주소를 설정
	SOCKADDR_IN servaddr = { 0 };//소켓주소
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr = GetDefaultMyIP();
	servaddr.sin_port = htons(PORT_NUM);

	//네트워크 인터페이스 결합
	int re = bind(sock, (struct sockaddr*) & servaddr, sizeof(servaddr));
	if (re == -1) { return -1; }

	//백로그 큐 설정
	re = listen(sock, blog);
	if (re == -1) { return -1; }
	
	return sock;
}

void AcceptLoop(SOCKET sock)
{
	SOCKET dosock;
	SOCKADDR_IN cliaddr = { 0 };
	int len = sizeof(cliaddr);
	while (true)
	{
		dosock = accept(sock, (SOCKADDR*)& cliaddr, &len); //연결 수락
		if (dosock == -1) {
			perror("Accept 실패");
			break;
		}
		printf("%s:%d의 연결 요청 수락\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
		DoIt(dosock);
	}
	closesocket(sock);
}

void DoIt(SOCKET dosock)
{
	char msg[MAX_MSG_LEN] = "";
	while (recv(dosock, msg, sizeof(msg), 0) > 0)//수신
	{
		printf("recv:%s\n", msg);
		send(dosock, msg, sizeof(msg), 0);//송신
	}
	closesocket(dosock);//소켓 닫기
}
