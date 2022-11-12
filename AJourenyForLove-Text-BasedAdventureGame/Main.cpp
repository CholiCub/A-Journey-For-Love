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
using namespace std;

void ToUpper(string& oldString);
void GetPlayerJournalSetting();
bool IsValidIntInEnum(const int numOfItems, int playerInput);
template <class myType> void PrintQuestionOptions(const int numOfOptions, string(*s)(myType));

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

	GetPlayerJournalSetting();
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

	std::cout << "Welcome to A Journey for Love";
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
	Player player(name, age, IdentityToString(Identity(identityNum)),
		RaceToString(Race(raceNum)), ReligionToString(Religion(religionNum)), BodyTypeToString(BodyType(bodyTypeNum)),
		EyeColorToString(EyeColor(eyeColorNum)), HairColorToString(HairColor(hairColorNum)),
		PartnerPreferenceToString(PartnerPreference(partnerPreferenceNum)));
	player.PrintPlayerInfo();
	std::cout << "\nThank you for entering your settings!" << endl;
}

template <class myType> void PrintQuestionOptions(const int numOfOptions,  string (*s)(myType)) {
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

