#pragma once
#include"Properties.h"
#include<string>
#include<iostream>

enum class EIdentity {
	Man = 1,
	Woman,
	CisWoman,
	TransWoman,
	CisMan,
	TransMan,
	NonBinary
};

class Identity : public Properties {
	const int NUM_OF_OPTIONS = 7;
public:
	std::string ToString(EIdentity i);
	void DisplayOptions() override;
	bool IsValidIntInEnum(int playerInput) override;
};
