#pragma once
#include<string>
using namespace std;

const int NUM_OF_EYE_COLORS = 5;

enum class EEyeColor {
	Brown = 1,
	Green,
	Blue,
	Hazel,
	Other
};

string EyeColorToString(EEyeColor r);

