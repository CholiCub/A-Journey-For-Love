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
	os << "Name: " << p.name << endl;
	os << "Age: " << p.age << endl;
	os << "Identity: " << i.ToString(p.identity) << endl;
	os << "Race: " << ra.ToString(p.race) << endl;
	os << "Religion: " << re.ToString(p.religion) << endl;
	os << "Body Type: " << bt.ToString(p.bodyType) << endl;
	os << "Hair Color: " << hc.ToString(p.hairColor) << endl;
	os << "Eye Color: " << ec.ToString(p.eyeColor) << endl;
	os << "Partner Preference: " << pp.ToString(p.partnerPreference) << endl;
	return os;
}
