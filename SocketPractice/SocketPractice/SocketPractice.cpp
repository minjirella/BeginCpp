// SocketPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32")
#pragma warning(disable:4996)
//
//int WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData);
//	/*
//	wVersionRequested: 사용할 윈속 버전으로 상위 2바이트에는 주 버전 번호 하위 2바이트에는 부 버전 번호
//	만약 2.2 버전을 사용하려면 0x0202 혹은 매크로 함수를 이용하여 MAKEWORD(2, 2)
//	lpWSAData : 초기화 과정에서 윈속의 속성을 설정에 필요, 함수 내부에서 설정해 준다.
//	*/
//int WSACleanup(void);
//typedef struct WSAData 
//{
//	WORD                wVersion; // 버전
//	WORD                wHighVersion; //사용할 수 있는 상위 버전으로 wVersion과 일치한다.
//	char                   szDescription[WSADESCRIPTION_LEN + 1]; //윈속 설명
//	char                   szSystemStatus[WSASYS_STATUS_LEN + 1]; //상태 문자열
//	unsigned short     iMaxSockets; //최대 소켓 
//	unsigned short     iMaxUdpDg; //데이터 그램의 최대 크기
//	char FAR* lpVendorInfo; //벤더 정보( 큰 의미 없음)
//} WSADATA, FAR* LPWSADATA;

int main()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);//윈속 초기화

	printf("wHighVersion:%#x\n", wsadata.wHighVersion);//윈속상위버전
	printf("wVersion:%#x\n", wsadata.wVersion);//윈속버전
	printf("szDescription:%s\n", wsadata.szDescription);//윈속 설명
	printf("szSystemStatus:%s\n", wsadata.szSystemStatus);//윈속상태

	//의미상으로 최대 소켓 개수이나 확인해 보면 언제나 0(하위버전과 호환성을 위해 남겨둠)
	printf("iMaxSocket:%d\n", wsadata.iMaxSockets);
	//의미상으로 데이터 그램의 최대 크기이나 확인해 보면 언제나 0(하위버전과 호환성을 위해 남겨둠)
	printf("iMaxUdpDg:%d\n", wsadata.iMaxUdpDg);

	WSACleanup();//윈속 해제
	return 0;
}
