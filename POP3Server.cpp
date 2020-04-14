#include "POP3Server.h"


Database* Database::instance = 0;

POP3Server::POP3Server(int port) {

	struct sockaddr_in serverAddr;
	int listener;

	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) {
		fprintf(stderr, "WSAStartup failed!\n");
		exit(1);
	}

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	serverAddr.sin_port = htons(port);

	if ((listener = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		exit(1);
	}

	const int reuse = 1;
	if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(reuse)) < 0) {
		exit(1);
	}

	if (bind(listener, (struct sockaddr*) & serverAddr, sizeof(serverAddr)) < 0) {
		exit(1);
	}
	this->listener = listener;

	Database::getInstance(); //prisijungia prie DB 
}

POP3Server::~POP3Server() {
	WSACleanup();
	closesocket(listener);
	delete(Database::getInstance());
}

void POP3Server::run() {
	if ((listen(listener, 10)) < 0) {
		exit(1);
	}

	while (1) {
		int clientSocket;
		if ((clientSocket = accept(listener, (sockaddr*)NULL, NULL)) < 0) {
			exit(1);
		}
		Session* session = new Session(clientSocket);
		session->createThread().detach();
	}
}
