#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32")
#pragma warning(disable:4996)

#define PORT_NUM    10200
#define MAX_MSG_LEN 256
#define SERVER_IP   "192.168.34.50" //���� IP �ּ�
int main()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);//���� �ʱ�ȭ	

	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//���� ����
	if (sock == -1) { return -1; }

	SOCKADDR_IN servaddr = { 0 };//���� �ּ�
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
	servaddr.sin_port = htons(PORT_NUM);

	int re = 0;
	re = connect(sock, (struct sockaddr*) & servaddr, sizeof(servaddr));//���� ��û
	if (re == -1) { return -1; }

	char msg[MAX_MSG_LEN] = "";
	while (true)
	{
		gets_s(msg, MAX_MSG_LEN);
		send(sock, msg, sizeof(msg), 0);//�۽�
		if (strcmp(msg, "exit") == 0) { break; }
		recv(sock, msg, sizeof(msg), 0);//�۽�
		printf("����:%s\n", msg);
	}
	closesocket(sock);//���� �ݱ�
	WSACleanup();//���� ����ȭ
	return 0;
}