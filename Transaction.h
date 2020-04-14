#pragma once
#include "State.h"
#include "Dele.h"
#include "List.h"
#include "Noop.h"
#include "Quit.h"
#include "Retr.h"
#include "Rset.h"
#include "Stat.h"
#include "Top.h"

class Transaction : public State {
public:
	Transaction() {
		init(std::vector <Command*> { new Dele(this), new List(this), new Noop(this), new Quit(true), new Retr(this), new Rset(this), new Stat(this), new Top(this)});
	};
	~Transaction() {};
};