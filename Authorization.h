#pragma once
#include "Transaction.h"
#include "User.h"
#include "Pass.h"
#include "Quit.h"


class Authorization : public State {
public:
	Authorization(){ 
		init(std::vector <Command*> {new User(this), new Pass(new Transaction()), new Quit(false)});
	};
	~Authorization() {};
};