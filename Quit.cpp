#include "Quit.h"

Quit::Quit(bool cleanMessages) : Command("quit",NULL){
	this->cleanMessages = cleanMessages;
}

Quit::~Quit()
{
}

std::string Quit::run(char** argv, Client* client)
{
	std::string response = "+OK\r\n";
	if (cleanMessages) {
		client->updateDB();
		client->setNextState(this->getNextState());
	}else {
		client->setNextState(this->getNextState());
	}
	return response;
}
