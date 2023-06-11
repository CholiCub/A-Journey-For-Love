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

using namespace std;

void CreateNewPlayer();
int GetPlayerSettings(Properties* p);

int main() {

	PlayerPersistence pp;

	if (pp.IsFileEmpty()) {
		cout << "Welcome back to A Journey for Love" << endl;
		Player player = pp.read();
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

	int id = GetPlayerSettings(&identity);
	int ra = GetPlayerSettings(&race);
	int re = GetPlayerSettings(&religion);
	int bt = GetPlayerSettings(&bodyType);
	int hc = GetPlayerSettings(&hairColor);
	int ec = GetPlayerSettings(&eyeColor);
	int pp = GetPlayerSettings(&partnerPreference);

	Player createdPlayer(name, age, (EIdentity(id)), (ERace(ra)), (EReligion(re)), (EBodyType(bt)), (EHairColor(hc)), (EEyeColor(ec)), (EPartnerPreference(pp)));
	PlayerPersistence p;
	p.save(createdPlayer);
	createdPlayer.PrintPlayerInfo();

	cout << "\nThank you for entering your settings!" << endl;
}

int GetPlayerSettings(Properties* p) {
	int num = {};
	do {
		cout << "Enter the pp you best identify with: " << endl;
		p->DisplayOptions();
		cin >> num;
		if (!p->IsValidIntInEnum(num)) {
			cout << "Invalid entry. Try again." << endl << endl;
		}
	} while(!p->IsValidIntInEnum(num));
	return num;
}