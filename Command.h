#pragma once
#include <string>
#include "Client.h"
//#include "State.h"

class State;

class Command {
private:
	std::string command;
	State* nextState;
public:
	Command(std::string command,State* nextState);
	virtual ~Command();
	virtual std::string run(char** argv, Client* client) = 0;
	bool is(std::string command);
	State* getNextState() { return nextState; };
};

