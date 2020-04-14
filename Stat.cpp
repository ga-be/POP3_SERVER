#include "Stat.h"

Stat::Stat(State* state) : Command ("stat",state){

}

Stat::~Stat() {

}

std::string Stat::run(char** argv, Client* client)
{
	std::string response = "+ERR";
	if (strlen(*argv) == 0) {
		Mailbox* mailbox = client->getMailbox();
		response = "+OK ";
		response += std::to_string(mailbox->getCountUnmarked());
		response += " ";
		response += std::to_string(mailbox->getSizeUnmarked());
	}
	response += "\r\n";
	return response;
}
