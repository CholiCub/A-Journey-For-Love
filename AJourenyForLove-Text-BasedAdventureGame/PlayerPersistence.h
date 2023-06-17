#pragma once
#include<iostream>
#include<fstream>
#include "Player.h"
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class PlayerPersistence {
	const string DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE = "PlayerJournalSettings.json";
public:
	void save(Player& p);
	virtual Player read();
	bool IsFileEmpty();
};