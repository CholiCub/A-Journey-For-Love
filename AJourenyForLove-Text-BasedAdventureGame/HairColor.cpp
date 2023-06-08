#include "HairColor.h"
string HairColorToString(EHairColor h) {
	switch (h) {
	case EHairColor::NoHair:
		return "No hair/ Bald";
	case EHairColor::Black:
		return "Black";
	case EHairColor::Brown:
		return "Brown";
	case EHairColor::Blonde:
		return "Blonde";
	case EHairColor::Red:
		return "Red";
	case EHairColor::White:
		return "White";
	case EHairColor::Colorful:
		return "Colorful";
	}
}
