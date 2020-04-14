#include "Top.h"

Top::Top(State* state) : Command("top",state)
{
}

Top::~Top()
{
}

std::string Top::run(char** argv, Client* client)
{
	std::string response = "-ERR";
	int i = std::atoi(argv[0]);
	int j = std::atoi(argv[1]);
	Mailbox* mailbox = client->getMailbox();
	if (i >= 1 && i <= mailbox->getCount()) {
		if (!mailbox->marked(i)) {
			response = "+OK\r\n";
			std::string text = mailbox->getLetterText(i);
			const char* temp = text.c_str();
			int pos = 0;
			if ((pos = text.find("\r\n\r\n")) != std::string::npos) { // header section exists
				pos += 4;
				response.append(text, 0, pos);
				int start = pos;
				while ((pos = text.find("\r\n", pos)) != std::string::npos && j)
				{
					pos += 2;
					response.append(text, start, (int)pos - start);
					j--;
					start = pos;
				}
			}
			else { // no header section, but is it possible if we have convention on rfc822?
				int start = ++pos;
				response.append("\r\n");
				while ((pos = text.find("\r\n", pos)) != std::string::npos && j)
				{
					pos += 2;
					response.append(text, start, (int)pos - start);
					j--;
					start = pos;
				}
			}
			response.append(".\r\n");
		}
	}
	return response;
}
