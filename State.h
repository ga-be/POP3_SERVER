#pragma once
#include <vector>
#include <string>
#include "Command.h"

class State {
private:
	//State* nextState;
	std::vector <Command*> commands;
public:
	State();
	virtual ~State() ;
	void init(std::vector <Command*> commands);
	std::string run(std::string command, char** argv,Client* user);
	//State* getNextState();

protected:
	//void setNextState(State* state);
};