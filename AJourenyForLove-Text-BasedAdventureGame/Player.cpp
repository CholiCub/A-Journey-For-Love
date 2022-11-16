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
string Player::getIdentity() const {
	return this->identity;
}
void Player::setIdentity(const string& newIdentity) {
	this->identity = newIdentity;
}
string Player::getRace() const {
	return this->race;
}
void Player::setRace(const string& newRace) {
	this->race = newRace;
}
string Player::getReligion() const {
	return this->religion;
}
void Player::setReligion(const string& newReligion) {
	this->religion = newReligion;
}
string Player::getBodyType() const {
	return this->bodyType;
}
void Player::setBodyType(const string& newBodyType) {
	this->bodyType = newBodyType;
}
string Player::getHairColor() const {
	return this->hairColor;
}
void Player::setHairColor(const string& newHairColor) {
	this->hairColor = newHairColor;
}
string Player::getEyeColor() const {
	return this->eyeColor;
}
void Player::setEyeColor(const string& newEyeColor) {
	this->eyeColor = newEyeColor;
}
string Player::getPartnerPreference() const {
	return this->partnerPreference;
}
void Player::setPartnerPreference(const string& newPartnerPreference) {
	this->partnerPreference = newPartnerPreference;
}

void Player::FromJson(Player& p, const string dfile) {
	ifstream ifs;
	ifs.open(dfile);
	json data = json::parse(ifs);

	p.setName(data.at("Name").get<string>());
	p.setAge((data.at("Age").get<int>()));
	p.setIdentity(data.at("Identity").get<string>());
	p.setRace(data.at("Race").get<string>());
	p.setReligion(data.at("Religion").get<string>());
	p.setBodyType(data.at("BodyType").get<string>());
	p.setEyeColor(data.at("EyeColor").get<string>());
	p.setHairColor(data.at("HairColor").get<string>());
	p.setPartnerPreference(data.at("PartnerPreference").get<string>());
	ifs.close();
}

void Player::ToJson(nlohmann::json& j, const Player& p, const string dfile) {
	ofstream ofs;
	ofs.open(dfile);

	j["Name"] = p.getName();
	j["Age"] = p.getAge();
	j["Identity"] = p.getIdentity();
	j["Race"] = p.getRace();
	j["Religion"] = p.getReligion();
	j["BodyType"] = p.getBodyType();
	j["EyeColor"] = p.getEyeColor();
	j["HairColor"] = p.getHairColor();
	j["PartnerPreference"] = p.getPartnerPreference();
	ofs << j;
	ofs.close();
}