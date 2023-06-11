#pragma once
#include <string>
#include <iostream>
#include "Identity.h"
#include "Race.h"
#include "Religion.h"
#include "BodyType.h"
#include "HairColor.h"
#include "EyeColor.h"
#include "PartnerPreference.h"

using namespace std;

class Player {
private:
	std::string name; 
	int age;
	EIdentity identity;
	ERace race;
	EReligion religion;
	EBodyType bodyType;
	EHairColor hairColor;
	EEyeColor eyeColor;
	EPartnerPreference partnerPreference;

public:
	Player();
	Player(std::string name, int age, EIdentity identity, ERace race, EReligion religion, EBodyType bodyType, EHairColor hairColor, EEyeColor eyeColor, EPartnerPreference partnerPreference);
	
	void PrintPlayerInfo();

	std::string getName() const;
	void setName(const std::string& newName);
	int getAge() const;
	void setAge(int newAge);
	EIdentity getIdentity() const;
	void setIdentity(const EIdentity& newIdentity);
	ERace getRace() const;
	void setRace(const ERace& newRace);
	EReligion getReligion() const;
	void setReligion(const EReligion& newReligion);
	EBodyType getBodyType() const;
	void setBodyType(const EBodyType& newBodyType);
	EHairColor getHairColor() const;
	void setHairColor (const EHairColor& newHairColor);
	EEyeColor getEyeColor() const;
	void setEyeColor(const EEyeColor& newEyeColor);
	EPartnerPreference getPartnerPreference() const;
	void setPartnerPreference(const EPartnerPreference& newPartnerPreference);
	
};