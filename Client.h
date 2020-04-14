#pragma once
#include "Database.h"
#include <iostream>
#include "Mailbox.h"

class Authorization;
class State;

class Client {
private:
	std::string username;
	bool isLoggedIn;//veliau galbut pasalint
	State* nextState;
	Mailbox* mailbox;

public:
	Client();
	~Client();

	void setUsername(std::string username);
	std::string getUsername();

	bool clientExists(std::string username);
	bool validPassword(std::string password);

	void loggedIn(bool is);
	bool loggedIn();
	
	State* getNextState() { return nextState; };
	void setNextState(State* state) { nextState = state; };

	void loadMailbox();
	Mailbox* getMailbox();

	void updateDB();

};