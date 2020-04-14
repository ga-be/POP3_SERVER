#pragma once
#include <string>

class Letter {
private:
	int id;
	std::string text;
	std::string header;
	bool marked;
public:
//	Letter();
	Letter(int id,std::string msg);
	~Letter();
	int getId();
	int getSize();
	std::string getHeader();
	std::string getText();
	void mark(bool marked);
	bool getMark();
private:
	void format();
};