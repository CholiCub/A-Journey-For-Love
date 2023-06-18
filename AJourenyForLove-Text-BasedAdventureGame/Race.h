#pragma once
#include"Properties.h"
#include<string>
#include<iostream>

enum class ERace {
	AfricanAmerican = 1,
	Asian,
	Caucasian,
	Black,
	Indian,
	IndigenousOrAboriginal,
	LatinOrHispanic,
	MiddleEastern,
	Mixed,
	Other
};

class Race : public Properties{
public:
	Race() :Properties(10) {};
	std::string ToString(ERace r);
	void DisplayOptions() override;
};