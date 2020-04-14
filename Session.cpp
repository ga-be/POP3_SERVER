#include "Session.h"


Session::Session(int clientSocket) {
	this->clientSocket = clientSocket;
	this->user = new Client();
	this->currentState = this->user->getNextState();
	
}

Session::~Session() {
	delete(user);
	currentState = NULL;
}

void Session::run() {
	sendOk(&clientSocket); //place in POP3server?
	while (1) {
		std::string request = ""; //whole input line
		std::string response = "";
		std::string command = "";
		char** argv = new char*[2];
		argv[0] = new char[MAX_COMMAND_SIZE];
		argv[1] = new char[MAX_COMMAND_SIZE];
		int rc;
		if ((rc=getLine(clientSocket, &request))!=0) {
			parseCommand(request, &command, argv);
			toLowerCase(command);
			std::cout << argv[0];
			std::cout << argv[1];
			std::cout << command;
			response = currentState->run(command,argv,user);
			send(clientSocket, &response.at(0), response.length(), 0);
			if ((currentState = user->getNextState()) == NULL) { //means client entered QUIT command
				break;
			}

		}
		else if(rc == 0){ //something wrong haha, add when this equals zero, means client closed connection
			break;
		}
	}
	delete(this);
}

std::thread Session::createThread() {
	return std::thread(&Session::run, this);
}