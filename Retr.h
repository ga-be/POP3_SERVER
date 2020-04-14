#pragma once
#include "Command.h"

class Retr : public Command {
private:

public:
	Retr(State* state);
	~Retr();

	// Inherited via Command
	virtual std::string run(char** argv, Client* client) override;
};