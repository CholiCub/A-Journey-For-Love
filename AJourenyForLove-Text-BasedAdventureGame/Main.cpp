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
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

void CreateNewPlayer(json& JSON);
bool IsValidIntInEnum(const int numOfItems, int playerInput);
template <class myType> void TPrintQuestionOptions(const int numOfOptions, string(*s)(myType));
bool IsReturningPlayer();
bool IsFileEmpty(ifstream& pFile);

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

void CreateNewPlayer( json& JSON) {
	string name{};
	int age{}, identityNum{}, raceNum{}, bodyTypeNum{}, religionNum{}, hairColorNum{}, eyeColorNum{}, partnerPreferenceNum{};
	bool IsIdenityValid{}, IsRaceValid{}, IsBodyTypeValid{}, IsReligionValid{}, IsEyeColorValid{}, IsHairColorValid{}, IsPartnerPreferenceValid{};

	std::cout << "\nEnter first name: ";
	getline(std::cin, name);

	do {
		std::cout << "Enter age: ";
		cin >> age;
	} while (!(age >= 18 && age < 105));

	do {
		std::cout << "Enter the identity you best identify with: " << endl;
		TPrintQuestionOptions(NUM_OF_IDENTITIES, IdentityToString);
		std::cin >> identityNum;
		IsIdenityValid = IsValidIntInEnum(NUM_OF_IDENTITIES, identityNum);
		if (!IsIdenityValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsIdenityValid);
	do {
		std::cout << "Enter the race you best identify with: " << endl;
		TPrintQuestionOptions(NUM_OF_RACES, RaceToString);
		std::cin >> raceNum;
		IsRaceValid = IsValidIntInEnum(NUM_OF_RACES, raceNum);
		if (!IsRaceValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsRaceValid);
	do {
		std::cout << "Enter the body type that best describes you: " << endl;
		TPrintQuestionOptions(NUM_OF_BODY_TYPES, BodyTypeToString);
		std::cin >> bodyTypeNum;
		IsBodyTypeValid = IsValidIntInEnum(NUM_OF_BODY_TYPES, bodyTypeNum);
		if (!IsBodyTypeValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsBodyTypeValid);
	do {
		std::cout << "Enter the religion that best describes you: " << endl;
		TPrintQuestionOptions(NUM_OF_RELIGION, ReligionToString);
		std::cin >> religionNum;
		IsReligionValid = IsValidIntInEnum(NUM_OF_RELIGION, religionNum);
		if (!IsBodyTypeValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsReligionValid);
	do {
		std::cout << "Enter your partner preference: " << endl;
		TPrintQuestionOptions(NUM_OF_PARTNER_PREFERENCE, PartnerPreferenceToString);
		std::cin >> partnerPreferenceNum;
		IsPartnerPreferenceValid = IsValidIntInEnum(NUM_OF_PARTNER_PREFERENCE, partnerPreferenceNum);
		if (!IsPartnerPreferenceValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsPartnerPreferenceValid);
	do {
		std::cout << "Enter your eye color: " << endl;
		TPrintQuestionOptions(NUM_OF_EYE_COLORS, EyeColorToString);
		std::cin >> eyeColorNum;
		IsEyeColorValid = IsValidIntInEnum(NUM_OF_EYE_COLORS, eyeColorNum);
		if (!IsEyeColorValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsEyeColorValid);
	do {
		std::cout << "Enter your hair color: " << endl;
		TPrintQuestionOptions(NUM_OF_HAIR_COLORS, HairColorToString);
		std::cin >> hairColorNum;
		IsHairColorValid = IsValidIntInEnum(NUM_OF_HAIR_COLORS, hairColorNum);
		if (!IsHairColorValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsHairColorValid);

	Player createdPlayer(name, age, IdentityToString(EIdentity(identityNum)),
		RaceToString(ERace(raceNum)), ReligionToString(EReligion(religionNum)), BodyTypeToString(EBodyType(bodyTypeNum)),
		EyeColorToString(EEyeColor(eyeColorNum)), HairColorToString(EHairColor(hairColorNum)),
		PartnerPreferenceToString(EPartnerPreference(partnerPreferenceNum)));
	//Create JSON file to store player data
	createdPlayer.ToJson(JSON, createdPlayer, DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
	createdPlayer.PrintPlayerInfo();
	std::cout << "\nThank you for entering your settings!" << endl;
}

template <class myType> void TPrintQuestionOptions(const int numOfOptions, string(*s)(myType)) {
	for (int i = 1; i <= numOfOptions; i++) {
		std::cout << i << "." << s(myType(i)) << endl;
	}
}

bool IsValidIntInEnum(const int numOfItems, int playerInput) {
	if (playerInput > 0 && playerInput <= numOfItems) {
		return true;
	}
	else return false;
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