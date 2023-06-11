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
#include "JsonPersistence.h"

using namespace std;

void CreateNewPlayer();
bool IsReturningPlayer();
int GetPlayerSettings(Properties* pp);

int main() {

	JsonPersistence jp;

	if (IsReturningPlayer()) {
		std::cout << "Welcome back to A Journey for Love" << endl;
		Player player = jp.read();
		player.PrintPlayerInfo();
	}
	else {
		std::cout << "Welcome to A Journey for Love" << endl;
		CreateNewPlayer();
	}
	cout << "\nThank you for playing!" << endl;
}
void CreateNewPlayer() {
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
	JsonPersistence jp;
	jp.save(createdPlayer);
	createdPlayer.PrintPlayerInfo();

	std::cout << "\nThank you for entering your settings!" << endl;
}

bool IsReturningPlayer() {
	JsonPersistence jp;
	if (!jp.IsFileEmpty()) return true;
	else return false;	
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