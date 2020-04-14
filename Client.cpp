#include "Client.h"
#include "Authorization.h"

static int callback(void* data, int argc, char** argv, char** azColName) {
	bool* exist = (bool*)data;
	if ((int)(*argv[0]-'0') == 1) {
		*exist = true;
	}
	return 0;
}

Client::Client() {
	username = "";
	nextState = new Authorization();
	mailbox = new Mailbox();
}

Client::~Client() {
	delete(nextState);
	delete(mailbox);
}

void Client::setUsername(std::string username) {
	this->username = username;
}

std::string Client::getUsername() {
	return username;
}

void Client::loggedIn(bool is) {
	this->isLoggedIn = is;
}

bool Client::loggedIn() {
	return isLoggedIn;
}

bool Client::clientExists(std::string username) {
	Database* db = db->getInstance();
	char* zErrMsg = 0;
	bool* exist = new bool(false);
	std::string stmt="SELECT COUNT(*) FROM users WHERE user='"+username+"';";
	db->execute(stmt, callback,exist);
	return *exist;
}

bool Client::validPassword(std::string password) {
	if (this->username.empty()) {
		return false;				//USERNAME NOT SET;
	}
	Database* db = db->getInstance();
	bool* exist = new bool(false);
	std::string stmt = "SELECT COUNT(*) FROM users WHERE user='" + this->username + "' AND password='" + password + "';";
	db->execute(stmt, callback, exist);
	return *exist;
}

void Client::loadMailbox() {
	mailbox->loadMailbox(username);
}

Mailbox* Client::getMailbox() {
	return mailbox;
}

void Client::updateDB() {
	mailbox->updateDB(username);
}
