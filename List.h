#pragma once
#include "Command.h"

class List : public Command {
private:

public:
	List(State* state);
	~List();

	// Inherited via Command
	virtual std::string run(char** argv,Client* client) override;
};