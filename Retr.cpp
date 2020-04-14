#include "Retr.h"

Retr::Retr(State* state) : Command("retr",NULL) {

}

Retr::~Retr() {

}

std::string Retr::run(char** argv, Client* client)
{
	std::string response = "-ERR\r\n";
	int i = std::atoi(argv[0]);
	Mailbox* mailbox = client->getMailbox();
	if (i >= 1 && i <= mailbox->getCount()) {
		if (!mailbox->marked(i)) {
			response = "+OK\r\n";
			response.append(mailbox->getLetterText(i));
			response.append(".\r\n");
		}
	}
	return response;
}
