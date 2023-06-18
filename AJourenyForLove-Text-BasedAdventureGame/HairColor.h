#pragma once
#include"Properties.h"
#include<string>

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
public:
	HairColor() :Properties(7) {};
	std::string ToString(EHairColor h);
	void DisplayOptions() override;
};