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
#include "PlayerPersistence.h"
#include "Properties.h"

using namespace std;

void CreateNewPlayer();
void PrintPlayerInfo(const Player& p);

int main() {

	PlayerPersistence pp;

	if (!pp.IsEmpty()) {
		cout << "Welcome back to A Journey for Love" << endl;
		Player player = pp.read();
		PrintPlayerInfo(player);
	}
	else {
		cout << "Welcome to A Journey for Love" << endl;
		CreateNewPlayer();
	}
	cout << "\nThank you for playing!" << endl;
}
void CreateNewPlayer() {
	string name{};
	int age{};
	cout << "\nEnter first name: ";
	getline(cin, name);
	do {
		cout << "Enter age: ";
		cin >> age;
	} while (!(age >= 18 && age < 105));
	Identity identity;
	Race race;
	Religion religion;
	BodyType bodyType;
	HairColor hairColor;
	EyeColor eyeColor;
	PartnerPreference partnerPreference;
	
	int id = identity.GetPlayerSettings();
	int ra = race.GetPlayerSettings();
	int re = religion.GetPlayerSettings();
	int bt = bodyType.GetPlayerSettings();
	int hc = hairColor.GetPlayerSettings();
	int ec = eyeColor.GetPlayerSettings();
	int pp = partnerPreference.GetPlayerSettings();

	Player createdPlayer(name, age, (EIdentity(id)), (ERace(ra)), (EReligion(re)), (EBodyType(bt)), (EHairColor(hc)), (EEyeColor(ec)), (EPartnerPreference(pp)));
	PlayerPersistence p;
	p.save(createdPlayer);
	PrintPlayerInfo(createdPlayer);

	cout << "\nThank you for entering your settings!" << endl;
}

void PrintPlayerInfo(const Player& p) {
	std::cout << "Your Settings: " << endl;
	std::cout << "---------------------------------" << endl;
	cout << p << endl;
}