#include "Noop.h"

Noop::Noop(State* state) : Command("noop",state) {

}

Noop::~Noop() {

}

std::string Noop::run(char** argv, Client* client)
{
	return "+OK\r\n";
}
