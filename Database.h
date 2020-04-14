#pragma once
#include "sqlite/sqlite3.h"
#include <string>

#define PATH "DB/db.db"

class Database {
private:
	static Database* instance;
	Database();
public:
	sqlite3* db;
	static Database* getInstance();
	~Database();
	void connect(const char* filename);
	void execute(std::string statement, int (*callback)(void*, int, char**, char**), void* firstArg = 0);
};