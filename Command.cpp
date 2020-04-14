#include "Command.h"
#include "State.h"


Command::Command(std::string command, State* nextState) {
	this->nextState = nextState;
	this->command = command;
}

Command::~Command() {
	nextState = NULL;
}

bool Command::is(std::string command) {
	bool is = this->command == command;
	return is;
}



