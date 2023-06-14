#pragma once
class Properties {
public:
	virtual void DisplayOptions() = 0;
	virtual bool IsValidIntInEnum(int playerInput) = 0;
	int GetPlayerSettings();
};

