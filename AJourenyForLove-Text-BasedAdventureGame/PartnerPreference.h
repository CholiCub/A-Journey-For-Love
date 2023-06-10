#pragma once
#include"Properties.h"
#include<string>
#include<iostream>

enum class EPartnerPreference {
	male = 1,
	female,
	both
};

class PartnerPreference : public Properties{
	const int NUM_OF_OPTIONS = 3;
public:
	std::string ToString(EPartnerPreference pp);
	void DisplayOptions() override;
	bool IsValidIntInEnum(int playerInput) override;
};