#pragma once
#include<string>
using namespace std;

const int NUM_OF_HAIR_COLORS = 7;

enum class EHairColor {
	NoHair=1,
	Black,
	Brown,
	Blonde,
	Red,
	White,
	Colorful
};

string HairColorToString(EHairColor h);
