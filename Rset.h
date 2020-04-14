#pragma once
#include "Command.h"

class Rset : public Command {
private:

public:
	Rset(State* state);
	~Rset();

	// Inherited via Command
	virtual std::string run(char** argv, Client* client) override;
};