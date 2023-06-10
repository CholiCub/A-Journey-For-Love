#include "PartnerPreference.h"

std::string PartnerPreference::ToString(EPartnerPreference pp) {
	switch (pp) {
	case EPartnerPreference::male:
		return "Male";
	case EPartnerPreference::female:
		return "Female";
	case EPartnerPreference::both:
		return "Both male and female";
	}
}

void PartnerPreference::DisplayOptions() {
	for (int i = 1; i <= NUM_OF_OPTIONS; i++) {
		std::cout << i << "." << ToString(EPartnerPreference(i)) << std::endl;
	}
}

bool PartnerPreference::IsValidIntInEnum(int playerInput) {
	if (playerInput > 0 && playerInput <= NUM_OF_OPTIONS) return true;
	else return false;
}