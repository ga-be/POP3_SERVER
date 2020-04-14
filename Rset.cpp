#include "Rset.h"

Rset::Rset(State* state) : Command("rset",state) {

}

Rset::~Rset() {

}

std::string Rset::run(char** argv, Client* client)
{
	std::string response = "-ERR";
	if (strlen(*argv) == 0) {
		Mailbox* mailbox = client->getMailbox();
		mailbox->unmarkAll();
		response = "+OK";
	}
	response.append("\r\n");
	return response;
}
