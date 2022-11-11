#pragma once
#include<string>
using namespace std;
const int NUM_OF_RELIGION = 16;

enum class Religion {
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
string ReligionToString(Religion r);

