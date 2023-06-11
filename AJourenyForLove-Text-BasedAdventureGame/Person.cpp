#include "Person.h"
#include<iostream>

Person::Person(std::string name, int age, EIdentity identity, ERace race, EReligion religion, EBodyType bodyType, EHairColor hairColor, EEyeColor eyeColor, EPartnerPreference partnerPreference) {
	this->name = name;
	this->age = age;
	this->identity = identity;
	this->race = race;
	this->religion = religion;
	this->bodyType = bodyType;
	this->hairColor = hairColor;
	this->eyeColor = eyeColor;
	this->partnerPreference = partnerPreference;
}

void Person::PrintInfo() {
	Identity id;
	Race ra;
	Religion re;
	BodyType bt;
	HairColor hc;
	EyeColor ec;
	PartnerPreference pp;
	std::cout << "Your Settings: " << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Identity: " << id.ToString(identity) << std::endl;
	std::cout << "Race: " << ra.ToString(race) << std::endl;
	std::cout << "Religion: " << re.ToString(religion) << std::endl;
	std::cout << "BodyType: " << bt.ToString(bodyType) << std::endl;
	std::cout << "EyeColor: " << ec.ToString(eyeColor) << std::endl;
	std::cout << "HairColor: " << hc.ToString(hairColor) << std::endl;
	std::cout << "PartnerPreference: " << pp.ToString(partnerPreference) << std::endl;
}

std::string Person::getName() const {
	return this->name;
}

int Person::getAge() const {
	return this->age;
}

EIdentity Person::getIdentity() const {
	return this->identity;
}

ERace Person::getRace() const {
	return this->race;
}

EReligion Person::getReligion() const {
	return this->religion;
}

EBodyType Person::getBodyType() const {
	return this->bodyType;
}

EHairColor Person::getHairColor() const {
	return this->hairColor;
}

EEyeColor Person::getEyeColor() const {
	return this->eyeColor;
}

EPartnerPreference Person::getPartnerPreference() const {
	return this->partnerPreference;
}