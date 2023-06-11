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

class Person {
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
	Person(std::string name, int age, EIdentity identity, ERace race, EReligion religion, EBodyType bodyType, EHairColor hairColor, EEyeColor eyeColor, EPartnerPreference partnerPreference);

	void PrintInfo();

	std::string getName() const;
	int getAge() const;
	EIdentity getIdentity() const;
	ERace getRace() const;
	EReligion getReligion() const;
	EBodyType getBodyType() const;
	EHairColor getHairColor() const;
	EEyeColor getEyeColor() const;
	EPartnerPreference getPartnerPreference() const;
};

