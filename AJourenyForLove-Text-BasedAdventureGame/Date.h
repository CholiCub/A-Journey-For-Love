#pragma once
#include<string>
using namespace std;

class Date {
private:
	string name, identity, race, bodyType, religion, hairColor, eyeColor, partnerPreference, personalityType, intention, relationshipLevel;
	int age, connectionPoints;
public:
	Date(string name, int age, string identity, string race, string religion, string bodyType, string hairColor, string eyeColor, string partnerPreference,
		string personalityType, string intention, string relationshipLevel, int connectionPoints);
	void PrintDateInfo();

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
	void setHairColor(const string& newHairColor);
	string getEyeColor() const;
	void setEyeColor(const string& newEyeColor);
	string getPartnerPreference() const;
	void setPartnerPreference(const string& newPartnerPreference);
	string getPersonalityType() const;
	void setPersonalityType(const string& newPersonalityType);
	string getIntention() const;
	void setIntention(const string& newIntention);
	string getRelationshipLevel() const;
	void setRelationshipLevel(const string& newRelationshipLevel);
	int getConnectionPoints() const;
	void setConnectionPoints(int newConnectionPoints);
};