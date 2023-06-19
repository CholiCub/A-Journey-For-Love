#pragma once
#include "Person.h"
#include"PersonalityType.h"
#include"Intention.h"
#include"RelationshipLevel.h"

class Date : public Person{
private:
	int connectionPoints;
	EPersonalityType personalityType;
	EIntention intention;
	ERelationshipLevel relationshipLevel;
public:
	Date(int cp, EPersonalityType pt, EIntention i, ERelationshipLevel rl)
		:Person(name, age, identity, race, religion, bodyType, hairColor, eyeColor, partnerPreference),
		connectionPoints(cp), personalityType(pt), intention(i), relationshipLevel(rl) {};
};

