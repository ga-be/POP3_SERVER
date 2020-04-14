#include "Letter.h"

/*Letter::Letter() {
	marked = false;
}*/

Letter::Letter(int id,std::string msg) {
	this->id = id;
	text = msg;
	marked = false;
	format();
}

Letter::~Letter() {

}

int Letter::getId() {
	return id;
}

bool Letter::getMark() {
	return marked;
}

void Letter::mark(bool marked) {
	this->marked = marked;
}

std::string Letter::getHeader() {
	return "";
}

void Letter::format(){
	int i = 0;
	while ((i=text.find('\n',i))!=std::string::npos)
	{
		text.insert(i,"\r");
		i += 2;
	}
	text.append("\r\n");
}

std::string Letter::getText() {
	return text;
}

int Letter::getSize() {
	return text.length();
}