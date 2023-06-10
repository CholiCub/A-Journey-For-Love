#pragma once
#include"Properties.h"
#include<string>
#include<iostream>

enum class EBodyType {
	Thin = 1,
	Athletic,
	Average,
	AFewExtra,
	BigTallOrBBW
};

class BodyType : public Properties {
	const int NUM_OF_OPTIONS = 5;
public:
	std::string ToString(EBodyType b);
	void DisplayOptions() override;
	bool IsValidIntInEnum(int playerInput) override;
};