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
	Date();
};

