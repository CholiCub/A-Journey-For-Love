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
public:
	PartnerPreference() :Properties(3) {};
	std::string ToString(EPartnerPreference pp);
	void DisplayOptions() override;
};