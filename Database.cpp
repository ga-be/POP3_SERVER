#include "Database.h"

Database* Database::getInstance() {
	if (!instance) {
		instance = new Database();
	}
	return instance;
}

Database::Database() {
	connect(PATH);
}

Database::~Database() {
	sqlite3_close(db);
}

void Database::connect(const char* filename) {
	int rc;
	rc = sqlite3_open(filename, &db);
	if (rc) {
		fprintf(stderr, "[-] Can't open database : %s\n", sqlite3_errmsg(db));
		sqlite3_close(db); //reiktu rimciau handlinti.
	}
}

void Database::execute(std::string statement, int (*callback)(void*, int, char**, char**),void* firstArg) {
	char* zErrMsg = 0;
	int rc = sqlite3_exec(db, &statement.at(0), (sqlite3_callback)callback, firstArg, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg); //HANDLE ERROR, reiketu pridet kad grazina atitinkama reiksme ir baigia threada
	}
}





