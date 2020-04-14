#pragma once
#include "Command.h"

class Dele : public Command {
private:

public:
	Dele(State* state);
	~Dele();

	// Inherited via Command
	virtual std::string run(char** argv,Client* client) override;
};