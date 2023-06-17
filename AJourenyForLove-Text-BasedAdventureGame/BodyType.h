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
public:
	BodyType() :Properties(5) {};
	std::string ToString(EBodyType b);
	void DisplayOptions() override;
};