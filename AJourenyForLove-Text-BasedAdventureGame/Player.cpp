#include "Player.h"
#include<iostream>

Player::Player(string name, int age, EIdentity identity, ERace race, EReligion religion, EBodyType bodyType, EHairColor hairColor, EEyeColor eyeColor, EPartnerPreference partnerPreference) {
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

string Player::getName() const {
	return this->name;
}

int Player::getAge() const{
	return this->age;
}

EIdentity Player::getIdentity() const {
	return this->identity;
}

ERace Player::getRace() const {
	return this->race;
}

EReligion Player::getReligion() const {
	return this->religion;
}

EBodyType Player::getBodyType() const {
	return this->bodyType;
}

EHairColor Player::getHairColor() const {
	return this->hairColor;
}

EEyeColor Player::getEyeColor() const {
	return this->eyeColor;
}

EPartnerPreference Player::getPartnerPreference() const {
	return this->partnerPreference;
}

ostream& operator<<(ostream& os, const Player& p) {
	Identity i;
	Race ra;
	Religion re;
	BodyType bt;
	HairColor hc;
	EyeColor ec;
	PartnerPreference pp;
	os << "Name: " << p.name <<"\n";
	os << "Age: " << p.age << "\n";
	os << "Identity: " << i.ToString(p.identity) << "\n";
	os << "Race: " << ra.ToString(p.race) << "\n";
	os << "Religion: " << re.ToString(p.religion) << "\n";
	os << "Body Type: " << bt.ToString(p.bodyType) << "\n";
	os << "Hair Color: " << hc.ToString(p.hairColor) << "\n";
	os << "Eye Color: " << ec.ToString(p.eyeColor) << "\n";
	os << "Partner Preference: " << pp.ToString(p.partnerPreference) << "\n";
	return os;
}
