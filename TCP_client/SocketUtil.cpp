#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "SocketUtil.h"

using namespace std;

SocketUtil::SocketUtil() {
	if (WSAStartup(MAKEWORD(2,2),&wsa)!=0) {
		cout << "Failed. Error code: " << WSAGetLastError()<<endl;
		exit(EXIT_FAILURE);
	}
	if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR) {
		cout << "Socket initialization failed" << WSAGetLastError << endl;
		exit(EXIT_FAILURE);
	}
	memset((char *)&client_si,0,sizeof(client_si));
	client_si.sin_family = AF_INET;
	client_si.sin_port = htons(port );
	//client_si.sin_addr.s_addr = htonl(INADDR_ANY);
	client_si.sin_addr.s_addr = inet_addr(address.c_str());
}

void SocketUtil::sendData(const char* buffer) {
	if (sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&client_si, socketlen) == SOCKET_ERROR) {
		cout<<"successfully sent"<<endl;
		exit(EXIT_FAILURE);
	}
	closesocket(sock);
}