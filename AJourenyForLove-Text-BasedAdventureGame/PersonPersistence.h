#pragma once
#include"Player.h"
class PersonPersistence {
	virtual void save(Player& p) = 0;
	virtual Player read() = 0;
};

