#pragma once
#include <iostream>

class Properties {
protected:
	const int NUM_OF_OPTIONS;
public:
	Properties(const int i) :NUM_OF_OPTIONS(i) {};
	virtual void DisplayOptions() = 0;
	bool IsValidIntInEnum(int playerInput);
	int GetPlayerSettings();
};