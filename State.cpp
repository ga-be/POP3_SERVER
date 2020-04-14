#include "State.h"

State::State() {
}

State::~State() {
	commands.clear();
}

void State::init(std::vector <Command*> commands) {
	this->commands = commands;
}

std::string State::run(std::string command, char** argv, Client* user) {

	std::string response = "-ERR\r\n";

	for (auto i = commands.begin(); i != commands.end(); i++) {
		if ((*i)->is(command)) {
			std::string response=(*i)->run(argv,user);
			
			return response;
		}
	}
	return response;
}

/*State* State::getNextState() {
	return nextState;
}

void State::setNextState(State* state) {
	this->nextState = state;
}*/

