#include "util.h"


void sendOk(int *clientSocket) {
	send(*clientSocket, "+OK\r\n", 5, 0);
}

int getLine(int socket, std::string* result) {
	char buffer[BUFFER_SIZE];
	int len;
	char* current = buffer;
	*current = '\0';
	while (1)
	{
		if ((len = recv(socket, current, BUFFER_SIZE - strlen(buffer), 0)) > 0) {
			current += len;
			*current = '\0';
			if ((strstr(buffer, "\r\n")) != NULL) {
				*result = buffer;
				return 1;
			}
		}
		else if (len == 0) {
			return 0;
		}
	}
}

void toLowerCase(std::string &command) {
	for (char &c : command) {
		c = tolower(c);
	}
}


void parseCommand(std::string input, std::string* command, char** argv) { 
	int len = input.size()-3;// -\r\n
	int i = 0;
	while (i<=len && input.at(i)!=' ') {
		*command += input.at(i);
		i++;
	}
	//*command += '\0';

	i++; // skip space;
	
	int j = 0;
	int z = 0;
	argv[1][0] = '\0';
	while (i <= len) {
		if (input.at(i) == ' ') {
			argv[z][j] = '\0';
			z++;
			i++;
			j = 0;
		}
		argv[z][j] = input.at(i);
		j++;
		i++;
	}
	argv[z][j] = '\0';
}