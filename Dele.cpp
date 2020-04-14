#include "Dele.h"

Dele::Dele(State* state) : Command("dele",state) {

}

Dele::~Dele() {

}


std::string Dele::run(char** argv, Client* client)
{
	Mailbox* mailbox = client->getMailbox();
	int i = atoi(*argv);
	std::string response = "-ERR";
	if (strlen(*argv)!=0) {
		if (i >= 1 && i <= mailbox->getCount()) {
			if (!mailbox->marked(i)) {
				response = "+OK";
				mailbox->mark(i);
			}
		}
	}
	response.append("\r\n");
	return response;
}
