#include "List.h"

List::List(State* state) : Command("list",state) {

}

List::~List() {

}

std::string List::run(char** argv, Client* client)
{
	Mailbox* mailbox = client->getMailbox();
	int i = **argv - '0';
	std::string response = "-ERR";
		if (strlen(*argv) == 0) {
			response = "+OK ";
			response.append(std::to_string(mailbox->getCount()));
			response.append("\r\n");
			for (int i = 1; i <= mailbox->getCount(); i++) {
				if (!mailbox->marked(i))
				{
					response.append(std::to_string(i));
					response.append(" ");
					response.append(std::to_string(mailbox->letterSize(i)));
					response.append("\r\n");
				}
			}
			response.append(".");
		}
		else {
			if (i >= 1 && i <= mailbox->getCount()) {
				if (!mailbox->marked(i))
				{
					response = "+OK ";
					response.append(*argv);
					response.append(" ");
					response.append(std::to_string(mailbox->letterSize(i)));
				}
			}
		}
	response.append("\r\n");
	return response;
}
