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
	const int NUM_OF_OPTIONS = 6;
public:
	std::string ToString(ERelationshipLevel h);
	void DisplayOptions() override;
};