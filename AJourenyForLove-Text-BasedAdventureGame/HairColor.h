#pragma once
#include"Properties.h"
#include<string>
#include<iostream>

enum class EHairColor {
	NoHair = 1,
	Black,
	Brown,
	Blonde,
	Red,
	White,
	Colorful
};

class HairColor : public Properties {
	const int NUM_OF_OPTIONS = 7;
public:
	std::string ToString(EHairColor h);
	void DisplayOptions() override;
	bool IsValidIntInEnum(int playerInput) override;
};