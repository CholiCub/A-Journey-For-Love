#include "Date.h"
#include<iostream>

Date::Date(string name, int age, string identity, string race, string religion, string bodyType, string hairColor, string eyeColor, string partnerPreference,
			string personalityType, string intention, string relationshipLevel, int connectionPoints) {
	this->name = name;
	this->age = age;
	this->identity = identity;
	this->race = race;
	this->religion = religion;
	this->bodyType = bodyType;
	this->hairColor = hairColor;
	this->eyeColor = eyeColor;
	this->partnerPreference = partnerPreference;
	this->personalityType = personalityType;
	this->intention = intention;
	this->relationshipLevel = relationshipLevel;
	this->connectionPoints = connectionPoints;
}
void Date::PrintDateInfo() {
	std::cout << "Your Date's Settings: " << endl;
	std::cout << "---------------------------------" << endl;
	std::cout << "Name: " << name << endl;
	std::cout << "Age: " << age << endl;
	std::cout << "Identity: " << identity << endl;
	std::cout << "Race: " << race << endl;
	std::cout << "Religion: " << religion << endl;
	std::cout << "Body Type: " << bodyType << endl;
	std::cout << "Eye Color: " << eyeColor << endl;
	std::cout << "Hair Color: " << hairColor << endl;
	std::cout << "Partner Preference: " << partnerPreference << endl;
	std::cout << "Personality Type: " << personalityType << endl;
	std::cout << "Intention: " << intention << endl;
	std::cout << "Relationship Level: " << relationshipLevel << endl;
	std::cout << "Connection Points: " << connectionPoints << endl;
}

	string Date::getName() const {
		return this->name;
	}
	void Date::setName(const std::string & newName) {
		this->name = newName;
	}
	int Date::getAge() const {
		return this->age;
	}
	void Date::setAge(int newAge) {
		this->age = newAge;
	}
	string Date::getIdentity() const {
		return this->identity;
	}
	void Date::setIdentity(const string & newIdentity) {
		this->identity = newIdentity;
	}
	string Date::getRace() const {
		return this->race;
	}
	void Date::setRace(const string & newRace) {
		this->race = newRace;
	}
	string Date::getReligion() const {
		return this->religion;
	}
	void Date::setReligion(const string & newReligion) {
		this->religion = newReligion;
	}
	string Date::getBodyType() const {
		return this->bodyType;
	}
	void Date::setBodyType(const string & newBodyType) {
		this->bodyType = newBodyType;
	}
	string Date::getHairColor() const {
		return this->hairColor;
	}
	void Date::setHairColor(const string & newHairColor) {
		this->hairColor = newHairColor;
	}
	string Date::getEyeColor() const {
		return this->eyeColor;
	}
	void Date::setEyeColor(const string & newEyeColor) {
		this->eyeColor = newEyeColor;
	}
	string Date::getPartnerPreference() const {
		return this->partnerPreference;
	}
	void Date::setPartnerPreference(const string & newPartnerPreference) {
		this->partnerPreference = newPartnerPreference;
}