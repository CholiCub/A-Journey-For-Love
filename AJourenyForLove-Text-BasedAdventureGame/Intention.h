#pragma once
#include"Properties.h"
#include<string>

enum class EIntention {
	Fling = 1,
	Chat,
	Friendship,
	Casual,
	Partnership,
};

class Intention : public Properties {
public:
	Intention() :Properties(5) {};
	std::string ToString(EIntention h);
	void DisplayOptions() override;
};