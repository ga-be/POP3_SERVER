#pragma once
#include <thread>
#include "util.h"
#include "Client.h"
#include "Authorization.h"
#include <iostream>

class Session {
private:
	int clientSocket;
	Client* user;
	State* currentState;
public:
	Session(int clientSocket);
	~Session();
	std::thread createThread();
	void run();
};