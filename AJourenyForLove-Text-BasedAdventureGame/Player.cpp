#include "Player.h"
#include<iostream>

Player::Player() {
	name = {};
	age = {};
	identity = {};
	race = {};
	religion = {};
	bodyType = {};
	hairColor = {};
	eyeColor = {};
	partnerPreference = {};
}

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

void Player::PrintPlayerInfo() {
	Identity id;
	Race ra;
	Religion re;
	BodyType bt;
	HairColor hc;
	EyeColor ec;
	PartnerPreference pp;
	std::cout << "Your Settings: " << endl;
	std::cout << "---------------------------------"<< endl;
	std::cout << "Name: " << name << endl;
	std::cout << "Age: " << age << endl;
	std::cout << "Identity: " << id.ToString(identity) << endl;
	std::cout << "Race: " << ra.ToString(race) << endl;
	std::cout << "Religion: " << re.ToString(religion) << endl;
	std::cout << "BodyType: " << bt.ToString(bodyType) << endl;
	std::cout << "EyeColor: " << ec.ToString(eyeColor) << endl;
	std::cout << "HairColor: " << hc.ToString(hairColor) << endl;
	std::cout << "PartnerPreference: " << pp.ToString(partnerPreference) << endl;
}

string Player::getName() const {
	return this->name;
}

void Player::setName(const std::string& newName) {
	this->name = newName;
}

int Player::getAge() const{
	return this->age;
}

void Player::setAge(int newAge) {
	this->age = newAge;
}

EIdentity Player::getIdentity() const {
	return this->identity;
}

void Player::setIdentity(const EIdentity& newIdentity) {
	this->identity = newIdentity;
}

ERace Player::getRace() const {
	return this->race;
}

void Player::setRace(const ERace& newRace) {
	this->race = newRace;
}

EReligion Player::getReligion() const {
	return this->religion;
}

void Player::setReligion(const EReligion& newReligion) {
	this->religion = newReligion;
}

EBodyType Player::getBodyType() const {
	return this->bodyType;
}

void Player::setBodyType(const EBodyType& newBodyType) {
	this->bodyType = newBodyType;
}

EHairColor Player::getHairColor() const {
	return this->hairColor;
}

void Player::setHairColor(const EHairColor& newHairColor) {
	this->hairColor = newHairColor;
}

EEyeColor Player::getEyeColor() const {
	return this->eyeColor;
}

void Player::setEyeColor(const EEyeColor& newEyeColor) {
	this->eyeColor = newEyeColor;
}

EPartnerPreference Player::getPartnerPreference() const {
	return this->partnerPreference;
}

void Player::setPartnerPreference(const EPartnerPreference& newPartnerPreference) {
	this->partnerPreference = newPartnerPreference;
}
