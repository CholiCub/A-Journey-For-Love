#pragma once
#include"Properties.h"
#include<string>

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
public:
	Identity() :Properties(7) {};
	std::string ToString(EIdentity i);
	void DisplayOptions() override;
};