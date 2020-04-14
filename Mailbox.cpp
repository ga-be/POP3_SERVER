#include "Mailbox.h"


static int callback(void* data, int argc, char** argv, char** azColName) {
	Mailbox* mailbox = (Mailbox*)data;
	int i;
	bool marked = false;
	
	int msgId = *argv[0] - '0';
	std::string msg = argv[1];
	mailbox->addLetter(msgId,msg);

	return 0;

}

Mailbox::Mailbox() {
	letters = std::vector <Letter*>();
}

Mailbox::~Mailbox() {
	letters.clear();
}

void Mailbox::loadMailbox(std::string username) {
	Database* db = db->getInstance();
	bool* exist = new bool(false);
	std::string stmt = "SELECT messageId, msg FROM " + username +" WHERE marked=false;";
	db->execute(stmt, callback, this);
}

std::string Mailbox::getLetterText(int i) {
	Letter* letter = letters.at(--i);
	return letter->getText();
}

void Mailbox::addLetter(Letter* letter) {
	letters.push_back(letter);
}

void Mailbox::addLetter(int id,std::string letter) {
	letters.push_back(new Letter(id,letter));
}

void Mailbox::updateDB(std::string username) {
	Database* db = db->getInstance();
	for (auto i = letters.begin(); i != letters.end(); i++) {
		if ((*i)->getMark()) {
			std::string stmt = "UPDATE " + username + " SET marked=true WHERE messageId="+ std::to_string((*i)->getId()) +";";
			db->execute(stmt, nullptr);
		}
	}
}

int Mailbox::getCount() {
	return (int)letters.size();
}

int Mailbox::getSize() {
	int size=0;
	for (auto i = letters.begin(); i != letters.end(); i++) {
		size += (int)(*i)->getSize();
	}
	return size;
}

void Mailbox::unmarkAll() {
	for (auto i = letters.begin(); i != letters.end(); i++) {
		(*i)->mark(false);
	}
}

void Mailbox::mark(int i) {
	letters.at(--i)->mark(true);
}

bool Mailbox::marked(int i) {
	return letters.at(--i)->getMark();
}

int Mailbox::letterSize(int i) {
	return letters.at(--i)->getSize();
}

int Mailbox::getSizeUnmarked() {
	int size = 0;
	for (auto i = letters.begin(); i != letters.end(); i++) {
		if(!(*i)->getMark())
		size += (int)(*i)->getSize();
	}
	return size;
}

int Mailbox::getCountUnmarked() {
	int count = 0;
	for (auto i = letters.begin(); i != letters.end(); i++) {
		if (!(*i)->getMark()) 
		count++;
		
	}
	return count;
}