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
	const int NUM_OF_OPTIONS = 10;
public:
	std::string ToString(ERace r);
	void DisplayOptions() override;
	bool IsValidIntInEnum(int playerInput);
};