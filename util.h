#pragma once
#include <WinSock2.h>
#include <string>

#define BUFFER_SIZE 4096
#define MAX_COMMAND_SIZE 41

void sendOk(int *clientSocket);
int getLine(int socket, std::string* result);
void parseCommand(std::string input, std::string* command, char** argv);
void toLowerCase(std::string &command);