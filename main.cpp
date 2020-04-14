#include "POP3Server.h"

using namespace std;
#define PORT 110 //default POP3 port

int main() {
	POP3Server* server = new POP3Server(PORT);
	server->run();
	delete(server);
	return 0;
}


//TODO: fix erorr handling
//TODO: maybe class for multi and single line responses
//TODO: create class for responses