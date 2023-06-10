#pragma once
#include"Properties.h"
#include<string>
#include<iostream>

enum class EReligion {
	NonReligious = 1,
	Anglican,
	Baptist,
	Buddhist,
	Catholic,
	ChristianOther,
	EasternOrthdox,
	Hindi,
	Jewish,
	Lutheran,
	Methodist,
	Mormon,
	Muslim,
	Presbyterian,
	Spiritual,
	Other
};

class Religion : public Properties {
	const int NUM_OF_OPTIONS = 16;
public:
	std::string ToString(EReligion r);
	void DisplayOptions() override;
	bool IsValidIntInEnum(int playerInput) override;
};
