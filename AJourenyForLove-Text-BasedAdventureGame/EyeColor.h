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
public:
	EyeColor() :Properties(5) {};
	std::string ToString(EEyeColor r);
	void DisplayOptions() override;
};