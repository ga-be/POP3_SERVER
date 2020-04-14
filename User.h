#pragma once
#include "Command.h"

class User : public Command {
private:
public:
	User(State* state);
	~User();

	// Inherited via Command
	virtual std::string run(char** argv, Client* client) override;
};
