#include<iostream>
#include<string>
#include "Identity.h"
#include "Race.h"
#include "BodyType.h"
#include "Religion.h"
#include "HairColor.h"
#include "EyeColor.h"
#include "PartnerPreference.h"
#include "Player.h"
#include "Properties.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

void CreateNewPlayer(json& JSON);
bool IsReturningPlayer();
bool IsFileEmpty(ifstream& pFile);
int GetPlayerSettings(Properties* pp);

const string DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE = "PlayerJournalSettings.json";

int main() {

	json JSON;
	Player player{};
	
	if (IsReturningPlayer()) {
		std::cout << "Welcome back to A Journey for Love" << endl;
		player.FromJson(player, DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
		player.PrintPlayerInfo();
	}
	else {
		std::cout << "Welcome to A Journey for Love" << endl;
		CreateNewPlayer(JSON);
	}
	cout << "\nThank you for playing!" << endl;
}
void CreateNewPlayer(json& JSON) {
	string name{};
	int age{};
	std::cout << "\nEnter first name: ";
	getline(std::cin, name);
	do {
		std::cout << "Enter age: ";
		cin >> age;
	} while (!(age >= 18 && age < 105));
	Identity identity;
	Race race;
	Religion religion;
	BodyType bodyType;
	HairColor hairColor;
	EyeColor eyeColor;
	PartnerPreference partnerPreference;

	int id = GetPlayerSettings(&identity);
	int ra = GetPlayerSettings(&race);
	int re = GetPlayerSettings(&religion);
	int bt = GetPlayerSettings(&bodyType);
	int hc = GetPlayerSettings(&hairColor);
	int ec = GetPlayerSettings(&eyeColor);
	int pp = GetPlayerSettings(&partnerPreference);

	Player createdPlayer(name, age, (EIdentity(id)), (ERace(ra)), (EReligion(re)), (EBodyType(bt)), (EHairColor(hc)), (EEyeColor(ec)), (EPartnerPreference(pp)));
	//Create JSON file to store player data
	createdPlayer.ToJson(JSON, createdPlayer, DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
	createdPlayer.PrintPlayerInfo();
	std::cout << "\nThank you for entering your settings!" << endl;
}

bool IsReturningPlayer() {
	ifstream ifs;
	ifs.open(DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
	if (!IsFileEmpty(ifs)) {
		ifs.close();
		return true;
	}
	else {
		ifs.close();
		return false;
	}
}

bool IsFileEmpty(ifstream& pFile) {
	return pFile.peek() == ifstream::traits_type::eof();
}

int GetPlayerSettings(Properties* pp) {
	int num = {};
	do {
		std::cout << "Enter the pp you best identify with: " << endl;
		pp->DisplayOptions();
		std::cin >> num;
		if (!pp->IsValidIntInEnum(num)) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while(!pp->IsValidIntInEnum(num));
	return num;
}