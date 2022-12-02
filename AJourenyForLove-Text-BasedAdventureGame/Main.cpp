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
#include "Date.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

void ToUpper(string& oldString);
void GetPlayerJournalSetting();
bool IsValidIntInEnum(const int numOfItems, int playerInput);
template <class myType> void PrintQuestionOptions(const int numOfOptions, string(*s)(myType));
bool ReturningPlayer(Player p);
const string defaultPlayerJournalSettingsFile = "PlayerJournalSettings.json";
bool IsFileEmpty(ifstream& pFile);
void Game();
Player player{};
json j;

int main() {

	Identity identity{};
	Race race{};
	BodyType bodyType{};
	Religion religion{};
	HairColor hairColor{};
	EyeColor eyeColor{};
	PartnerPreference partnerPreference{};
	int age{};
	char dash{};
	int heightInInches{}, bodyTypeNum{};
	int likeAnimals{};
	bool identityValid{};

	if (ReturningPlayer(player)) {
		std::cout << "Welcome back to A Journey for Love" << endl;
		player.PrintPlayerInfo();
	}
	else {
		std::cout << "Welcome to A Journey for Love" << endl;
		GetPlayerJournalSetting();
	}
	Game();
	cout << "\n\nThank you for playing!" << endl;
}

void ToUpper(string& oldString) {
	getline(std::cin, oldString);
	for (int i = 0; i < oldString.length(); i++) {
		oldString[i] = toupper(oldString[i]);
	}
}

void GetPlayerJournalSetting() {
	bool playerInputValid{ };
	string name{};
	int age{};
	int identityNum{}, raceNum{}, bodyTypeNum{}, religionNum{}, hairColorNum{}, eyeColorNum{}, partnerPreferenceNum{};
	bool IsIdenityValid{};
	bool IsRaceValid{};
	bool IsBodyTypeValid{};
	bool IsReligionValid{};
	bool IsEyeColorValid{};
	bool IsHairColorValid{};
	bool IsPartnerPreferenceValid{};

	std::cout << "\nEnter first name: ";
	getline(std::cin, name);

	do {
		std::cout << "Enter age: ";
		cin >> age;
	} while (!(age >= 18 && age < 105));

	do {
		std::cout << "Enter the identity you best identify with: " << endl;
		PrintQuestionOptions(NUM_OF_IDENTITIES, IdentityToString);
		std::cin >> identityNum;
		IsIdenityValid = IsValidIntInEnum(NUM_OF_IDENTITIES, identityNum);
		if (!IsIdenityValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsIdenityValid);
	do {
		std::cout << "Enter the race you best identify with: " << endl;
		PrintQuestionOptions(NUM_OF_RACES, RaceToString);
		std::cin >> raceNum;
		IsRaceValid = IsValidIntInEnum(NUM_OF_RACES, raceNum);
		if (!IsRaceValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsRaceValid);
	do {
		std::cout << "Enter the body type that best describes you: " << endl;
		PrintQuestionOptions(NUM_OF_BODY_TYPES, BodyTypeToString);
		std::cin >> bodyTypeNum;
		IsBodyTypeValid = IsValidIntInEnum(NUM_OF_BODY_TYPES, bodyTypeNum);
		if (!IsBodyTypeValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsBodyTypeValid);
	do {
		std::cout << "Enter the religion that best describes you: " << endl;
		PrintQuestionOptions(NUM_OF_RELIGION, ReligionToString);
		std::cin >> religionNum;
		IsReligionValid = IsValidIntInEnum(NUM_OF_RELIGION, religionNum);
		if (!IsBodyTypeValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsReligionValid);
	do {
		std::cout << "Enter your partner preference: " << endl;
		PrintQuestionOptions(NUM_OF_PARTNER_PREFERENCE, PartnerPreferenceToString);
		std::cin >> partnerPreferenceNum;
		IsPartnerPreferenceValid = IsValidIntInEnum(NUM_OF_PARTNER_PREFERENCE, partnerPreferenceNum);
		if (!IsPartnerPreferenceValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsPartnerPreferenceValid);
	do {
		std::cout << "Enter your eye color: " << endl;
		PrintQuestionOptions(NUM_OF_EYE_COLORS, EyeColorToString);
		std::cin >> eyeColorNum;
		IsEyeColorValid = IsValidIntInEnum(NUM_OF_EYE_COLORS, eyeColorNum);
		if (!IsEyeColorValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsEyeColorValid);
	do {
		std::cout << "Enter your hair color: " << endl;
		PrintQuestionOptions(NUM_OF_HAIR_COLORS, HairColorToString);
		std::cin >> hairColorNum;
		IsHairColorValid = IsValidIntInEnum(NUM_OF_HAIR_COLORS, hairColorNum);
		if (!IsHairColorValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsHairColorValid);

	Player createdPlayer(name, age, IdentityToString(Identity(identityNum)),
		RaceToString(Race(raceNum)), ReligionToString(Religion(religionNum)), BodyTypeToString(BodyType(bodyTypeNum)),
		EyeColorToString(EyeColor(eyeColorNum)), HairColorToString(HairColor(hairColorNum)),
		PartnerPreferenceToString(PartnerPreference(partnerPreferenceNum)));
	player = createdPlayer;
	//Create JSON file to store player data
	player.ToJson(j, player, defaultPlayerJournalSettingsFile);
	player.PrintPlayerInfo();

	std::cout << "\nThank you for entering your settings!" << endl;
}

template <class myType> void PrintQuestionOptions(const int numOfOptions, string(*s)(myType)) {
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
bool ReturningPlayer(Player p) {
	ifstream ifs;
	ifs.open(defaultPlayerJournalSettingsFile);
	json j;
	if (!IsFileEmpty(ifs)) {
		player.FromJson(player, defaultPlayerJournalSettingsFile);
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
void Game() 	{
	Date tutorialDate("Sam", 30, "Trans Women", "Black", "Catholic", "Thin", "Black", "Brown", "Men", "Dominant", "Casual", "Stranger", 0);
	const string quote = "\"";
	
	cout << "\nMatchmaker:" + quote + "You are going to be going on a date with " + tutorialDate.getName() + quote + "\n";
	cout << "\nScene\n-----" << endl;
	cout << "You walk into the restaurant and see your date sitting at the table" << endl;
	cout << "Their " + tutorialDate.getHairColor() + " hair shimmering by the lamp above and their " + tutorialDate.getEyeColor() +
		" eyes staring up at you. You notice they appear to be of " + tutorialDate.getRace() + " decendants and " + tutorialDate.getBodyType() + ".\n";
	cout << "You sit down at the table with them.";
	cout << "\n" +tutorialDate.getName()+":" + quote + "Hi, I'm " + tutorialDate.getName() + quote + "\n";
}