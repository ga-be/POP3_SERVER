#include "User.h"
#include <iostream>


User::User(State* state) : Command("user",state){
	
}

User::~User()
{
}

std::string User::run(char** argv, Client* user)
{
	std::string response="-ERR"; 
	if (strlen(*argv)) {
		std::string name(*argv);
		bool is = user->clientExists(name);
		if (is) {
			user->setUsername(name);
			response = "+OK";
		}
	}
	response.append("\r\n");
	return response;

}
