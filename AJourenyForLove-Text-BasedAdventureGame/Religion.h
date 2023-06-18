#pragma once
#include"Properties.h"
#include<string>

enum class EReligion {
	NonReligious = 1,
	Anglican,
	Baptist,
	Buddhist,
	Catholic,
	ChristianOther,
	EasternOrthdox,
	Hindi,
	Jewish,
	Lutheran,
	Methodist,
	Mormon,
	Muslim,
	Presbyterian,
	Spiritual,
	Other
};

class Religion : public Properties {
public:
	Religion() :Properties(16) {};
	std::string ToString(EReligion r);
	void DisplayOptions() override;
};
