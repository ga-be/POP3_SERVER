#pragma once
#include "Command.h"


class Quit : public Command {
private:
	bool cleanMessages;
public:
	Quit(bool cleanMessages);
	~Quit();

	// Inherited via Command
	virtual std::string run(char** argv, Client* client) override;
};