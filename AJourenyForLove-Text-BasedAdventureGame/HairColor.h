#pragma once
#include<string>
using namespace std;

const int NUM_OF_HAIR_COLORS = 7;

enum class HairColor {
	NoHair=1,
	Black,
	Brown,
	Blonde,
	Red,
	White,
	Colorful
};

string HairColorToString(HairColor h);
