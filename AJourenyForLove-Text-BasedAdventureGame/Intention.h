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
	const int NUM_OF_OPTIONS = 5;
public:
	std::string ToString(EIntention h);
	void DisplayOptions() override;
};