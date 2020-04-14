#pragma once
#include <string>
#include <vector>
#include "Letter.h"
#include <iostream>
#include "Database.h"

class Mailbox {
private:
	std::vector <Letter*> letters;
public:
	Mailbox();
	~Mailbox();
	void loadMailbox(std::string username);
	void addLetter(Letter* letter);
	void addLetter(int id,std::string letter);
	void updateDB(std::string username);
	void mark(int i);
	bool marked(int i);
	void unmarkAll();
	int getCount();
	int getSize();
	int letterSize(int i);
	int getSizeUnmarked();
	int getCountUnmarked();
	std::string getLetterText(int i);
};