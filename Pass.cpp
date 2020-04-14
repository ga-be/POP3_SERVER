#include "Pass.h"

Pass::Pass(State* state) : Command("pass",state){
}

Pass::~Pass()
{
}

std::string Pass::run(char** argv, Client* client)
{
	std::string response = "-ERR";
	if (strlen(*argv) != 0) {
		std::string password(*argv);
		bool is = client->validPassword(*argv);
		if (is) {
			client->setNextState(this->getNextState());
			client->loadMailbox();
			response = "+OK";
		}
	}
	response.append("\r\n");
	return response;
}
