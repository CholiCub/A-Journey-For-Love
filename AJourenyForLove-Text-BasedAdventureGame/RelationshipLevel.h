#pragma once
#include"Properties.h"
#include<string>

enum class ERelationshipLevel {
	Stranger = 1,
	Relevant,
	Friend,
	Like,
	Love,
	Adore,
};

class RelationshipLevel : public Properties {
public:
	RelationshipLevel() :Properties(6) {};
	std::string ToString(ERelationshipLevel h);
	void DisplayOptions() override;
};