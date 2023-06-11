#pragma once
#include"PersonPersistence.h"
#include<fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class PlayerPersistence : public PersonPersistence{
	const string DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE = "PlayerJournalSettings.json";
public:
	virtual void save(Player& p) override;
	virtual Player read() override;
	bool IsFileEmpty();
};