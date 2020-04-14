#pragma once
#include "Command.h"

class Stat : public Command {
private:

public:
	Stat(State* state);
	~Stat();

	// Inherited via Command
	virtual std::string run(char** argv, Client* client) override;
};