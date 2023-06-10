#pragma once
#include"Properties.h"
#include<string>
#include<iostream>

enum class EEyeColor {
	Brown = 1,
	Green,
	Blue,
	Hazel,
	Other
};

class EyeColor : public Properties {
	const int NUM_OF_OPTIONS = 5;
public:
	std::string ToString(EEyeColor r);
	void DisplayOptions() override;
	bool IsValidIntInEnum(int playerInput) override;
};