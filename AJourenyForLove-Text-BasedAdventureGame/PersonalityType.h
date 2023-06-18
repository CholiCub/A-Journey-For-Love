#pragma once
#include"Properties.h"
#include<string>

enum class EPersonalityType {
	ISTJ = 1,
	INFJ,
	INTJ,
	ENFJ,
	ISTP,
	ESFJ,
	INFP,
	ESFP,
	ENFP,
	ESTP,
	ESTJ,
	ENTJ,
	INTP,
	ISFJ,
	ENTP,
	ISFP
};

class PersonalityType : public Properties {
public:
	PersonalityType() :Properties(16) {};
	std::string ToString(EPersonalityType h);
	void DisplayOptions() override;
};