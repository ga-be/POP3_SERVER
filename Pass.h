#pragma once
#include "Command.h"
#include "Transaction.h"

class Pass : public Command {
private:

public:
	Pass(State* state);
	~Pass();

	// Inherited via Command
	virtual std::string run(char** argv, Client* client) override;
};