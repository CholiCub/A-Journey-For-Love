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
	const int NUM_OF_OPTIONS = 16;
public:
	std::string ToString(EPersonalityType h);
	void DisplayOptions() override;
};