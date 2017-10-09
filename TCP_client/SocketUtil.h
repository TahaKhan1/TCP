
#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

class SocketUtil{
	private:
		struct sockaddr_in client_si;
		int sock, socketlen = sizeof(client_si);
		WSADATA wsa;
		const unsigned short port = 9999;
		const string address="127.0.0.1";

	public:
		SocketUtil();
		void sendData(const char*);
};