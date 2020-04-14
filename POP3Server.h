#pragma once
#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <iostream>
#include "Session.h"
#include "Database.h"



class POP3Server {
private:
	int listener;
public:
	POP3Server(int port);
	~POP3Server();
	void run();
};
