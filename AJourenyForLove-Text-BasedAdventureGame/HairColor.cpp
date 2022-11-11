#include "HairColor.h"
string HairColorToString(HairColor h) {
	switch (h) {
	case HairColor::NoHair:
		return "No hair/ Bald";
	case HairColor::Black:
		return "Black";
	case HairColor::Brown:
		return "Brown";
	case HairColor::Blonde:
		return "Blonde";
	case HairColor::Red:
		return "Red";
	case HairColor::White:
		return "White";
	case HairColor::Colorful:
		return "Colorful";
	}
}
