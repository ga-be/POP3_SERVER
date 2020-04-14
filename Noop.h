#pragma once
#include "Command.h"

class Noop : public Command {
private:

public:
	Noop(State* state);
	~Noop();

	// Inherited via Command
	virtual std::string run(char** argv, Client* client) override;
};