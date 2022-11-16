#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

class Player {
private:
	string name , identity, race, bodyType, religion, hairColor, eyeColor, partnerPreference;
	int age;

public:
	Player();
	Player(string name, int age, string identity, string race, string religion, string bodyType, string hairColor, string eyeColor, string partnerPreference);
	
	void PrintPlayerInfo();

	string getName() const;
	void setName(const std::string& newName);
	int getAge() const;
	void setAge(int newAge);
	string getIdentity() const;
	void setIdentity(const string& newIdentity);
	string getRace() const;
	void setRace(const string& newRace);
	string getReligion() const;
	void setReligion(const string& newReligion);
	string getBodyType() const;
	void setBodyType(const string& newBodyType);
	string getHairColor() const;
	void setHairColor (const string& newHairColor);
	string getEyeColor() const;
	void setEyeColor(const string& newEyeColor);
	string getPartnerPreference() const;
	void setPartnerPreference(const string& newPartnerPreference);

	//json serialization
	void FromJson(Player& p, const string dfile);
	void ToJson(nlohmann::json& j, const Player& p, const string dfile);
	};

