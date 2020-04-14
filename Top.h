#pragma once
#include "Command.h"

class Top : public Command {
private:

public:
	Top(State* state);
	~Top();

	// Inherited via Command
	virtual std::string run(char** argv, Client* client) override;
};