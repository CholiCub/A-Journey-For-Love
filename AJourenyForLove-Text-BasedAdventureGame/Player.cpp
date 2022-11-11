#include "Player.h"
#include<iostream>

Player::Player(string name, int age, string identity, string race, string religion, string bodyType, string hairColor, string eyeColor, string partnerPreference) {
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
	std::cout << "Your Settings: " << endl;
	std::cout << "---------------------------------"<< endl;
	std::cout << "Name: " << name << endl;
	std::cout << "Age: " << age << endl;
	std::cout << "Identity: " << identity << endl;
	std::cout << "Race: " << race << endl;
	std::cout << "Religion: " << religion << endl;
	std::cout << "BodyType: " << bodyType << endl;
	std::cout << "EyeColor: " << eyeColor << endl;
	std::cout << "HairColor: " << hairColor << endl;
	std::cout << "PartnerPreference: " << partnerPreference << endl;
}
