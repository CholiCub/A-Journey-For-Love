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

//protoypes
void ToUpper(string& oldString);

//player visuals
void GetPlayerJournalSetting();
void PrintIdentityOptions();
void PrintRaceOptions();
void PrintBodyTypeOptions();
void PrintReligionOptions(); 
void PrintEyeColorOptions();
void PrintHairColorOptions();
void PrintPartnerPreferenceOptions();
bool IsValidIntInEnum(const int NUM_OF_ITEMS, int playerInput);

string name{};
Identity identity{};
Race race{};
BodyType bodyType{};
Religion religion{};
HairColor hairColor{};
EyeColor eyeColor{};
PartnerPreference partnerPreference{};

int main() {
	int age{};
	char dash{};
	int heightInInches{}, bodyType{};
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
	int age{};
	int identityNum{}, raceNum{}, bodyTypeNum{}, religionNum{}, hairColorNum{}, eyeColorNum{},partnerPreferenceNum{};
	std::cout<<"Welcome to A Journey for Love";
	std::cout<<"\nEnter first name: ";
	getline(std::cin, name);

	do {
		std::cout << "Enter age: ";
		cin >> age;
	} while (!(age >= 18 && age<105));

	bool IsIdenityValid{};
	bool IsRaceValid{};
	bool IsBodyTypeValid{};
	bool IsReligionValid{};
	bool IsEyeColorValid{};
	bool IsHairColorValid{};
	bool IsPartnerPreferenceValid{};
	do {
		std::cout << "Enter the identity you best identify with: " << endl;
		PrintIdentityOptions();
		std::cin >> identityNum;
		IsIdenityValid = IsValidIntInEnum(NUM_OF_IDENTITIES, identityNum);
		if (!IsIdenityValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsIdenityValid);
	do {
		std::cout << "Enter the race you best identify with: " << endl;
		PrintRaceOptions();
		std::cin >> raceNum;
		IsRaceValid = IsValidIntInEnum(NUM_OF_RACES, raceNum);
		if (!IsRaceValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsRaceValid);
	do {
		std::cout << "Enter the body type that best describes you: " << endl;
		PrintBodyTypeOptions();
		
		std::cin >> bodyTypeNum;
		IsBodyTypeValid = IsValidIntInEnum(NUM_OF_BODY_TYPES, bodyTypeNum);
		if (!IsBodyTypeValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsBodyTypeValid);
	do {
		std::cout << "Enter the body type that best describes you: " << endl;
		PrintReligionOptions();
		
		std::cin >> religionNum;
		IsReligionValid = IsValidIntInEnum(NUM_OF_RELIGION, religionNum);
		if (!IsBodyTypeValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsReligionValid);
	//PartnerPreference
	do {
		std::cout << "Enter your partner preference: " << endl;
		PrintPartnerPreferenceOptions();
		std::cin >> partnerPreferenceNum;
		IsPartnerPreferenceValid = IsValidIntInEnum(NUM_OF_PARTNER_PREFERENCE, partnerPreferenceNum);
		if (!IsPartnerPreferenceValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsPartnerPreferenceValid);
		//EyeColor
	do {
		std::cout << "Enter your eye color: " << endl;
		PrintEyeColorOptions();
		std::cin >> eyeColorNum;
		IsEyeColorValid = IsValidIntInEnum(NUM_OF_EYE_COLORS, eyeColorNum);
		if (!IsEyeColorValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsEyeColorValid);
	//HairColor
	do {
		std::cout << "Enter your hair color: " << endl;
		PrintHairColorOptions();
		std::cin >> hairColorNum;
		IsHairColorValid = IsValidIntInEnum(NUM_OF_HAIR_COLORS, hairColorNum);
		if (!IsHairColorValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsHairColorValid);
	Player player(name,age, IdentityToString(Identity(identityNum)), 
		RaceToString(Race(raceNum)),ReligionToString(Religion(religionNum)),BodyTypeToString(BodyType(bodyTypeNum)),
		EyeColorToString(EyeColor(eyeColorNum)),HairColorToString(HairColor(hairColorNum)), 
		PartnerPreferenceToString(PartnerPreference(partnerPreferenceNum)));
	player.PrintPlayerInfo();
	std::cout << "Thank you for entering your settings!" << endl;
}

void PrintIdentityOptions() {
	for (int i = 1; i <= NUM_OF_IDENTITIES; i++) {
		std::cout << i << "." << IdentityToString(Identity(i)) << endl;
	}
}
void PrintRaceOptions() {
	for (int i = 1; i <= NUM_OF_RACES; i++) {
		std::cout << i << "." << RaceToString(Race(i)) << endl;
	}
}
void PrintBodyTypeOptions() {
	for (int i = 1; i <= NUM_OF_BODY_TYPES; i++) {
		std::cout << i << "." << BodyTypeToString(BodyType(i)) << endl;
	}
}
void PrintReligionOptions() {
	for (int i = 1; i <= NUM_OF_RELIGION; i++) {
		std::cout << i << "." << ReligionToString(Religion(i)) << endl;
	}
}
void PrintPartnerPreferenceOptions() {
	for (int i = 1; i <= NUM_OF_PARTNER_PREFERENCE; i++) {
		std::cout << i << "." << PartnerPreferenceToString(PartnerPreference(i)) << endl;
	}
}
void PrintEyeColorOptions() {
	for (int i = 1; i <= NUM_OF_EYE_COLORS; i++) {
		std::cout << i << "." << EyeColorToString(EyeColor(i)) << endl;
	}
}
void PrintHairColorOptions() {
	for (int i = 1; i <= NUM_OF_HAIR_COLORS; i++) {
		std::cout << i << "." << HairColorToString(HairColor(i)) << endl;
	}
}
bool IsValidIntInEnum(const int NUM_OF_ITEMS, int playerInput) {
	if (playerInput > 0 && playerInput <= NUM_OF_ITEMS) {
		return true;
	}
	else return false;
}

