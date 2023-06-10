#include "EyeColor.h"

std::string EyeColor::ToString(EEyeColor e) {
	switch (e) {
	case EEyeColor::Brown:
		return "Brown";
	case EEyeColor::Green:
		return "Green";
	case EEyeColor::Blue:
		return "Blue";
	case EEyeColor::Hazel:
		return "Hazel";
	case EEyeColor::Other:
		return "Other";
	}
}

void EyeColor::DisplayOptions() {
	for (int i = 1; i <= NUM_OF_OPTIONS; i++) {
		std::cout << i << "." << ToString(EEyeColor(i)) << std::endl;
	}
}

bool EyeColor::IsValidIntInEnum(int playerInput) {
	if (playerInput > 0 && playerInput <= NUM_OF_OPTIONS) return true;
	else return false;
}