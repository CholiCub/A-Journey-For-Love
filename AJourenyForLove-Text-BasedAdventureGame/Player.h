#pragma once
#include<string>
using namespace std;
class Player {
private:
	string name , identity, race, bodyType, religion, hairColor, eyeColor, partnerPreference;
	int age;
public:
	Player(string name, int age, string identity, string race, string religion, string bodyType, string hairColor, string eyeColor, string partnerPreference);
	void PrintPlayerInfo();

};

