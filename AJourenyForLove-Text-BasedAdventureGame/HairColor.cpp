#include "HairColor.h"

std::string HairColor::ToString(EHairColor h) {
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

void HairColor::DisplayOptions() {
	for (int i = 1; i <= NUM_OF_OPTIONS; i++) {
		std::cout << i << "." << ToString(EHairColor(i)) << std::endl;
	}
}