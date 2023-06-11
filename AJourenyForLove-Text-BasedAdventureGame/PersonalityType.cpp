#include "PersonalityType.h"

std::string PersonalityType::ToString(EPersonalityType h) {
	switch (h) {
	case EPersonalityType::ISTJ:
		return "ISTJ";
	case EPersonalityType::INFJ:
		return "INFJ";
	case EPersonalityType::INTJ:
		return "INTJ";
	case EPersonalityType::ENFJ:
		return "ENFJ";
	case EPersonalityType::ISTP:
		return "ISTP";
	case EPersonalityType::ESFJ:
		return "ESFJ";
	case EPersonalityType::INFP:
		return "INFP";
	case EPersonalityType::ESFP:
		return "ESFP";
	case EPersonalityType::ENFP:
		return "ENFP";
	case EPersonalityType::ESTP:
		return "ESTP";
	case EPersonalityType::ESTJ:
		return "ESTJ";
	case EPersonalityType::ENTJ:
		return "ENTJ";
	case EPersonalityType::INTP:
		return "INTP";
	case EPersonalityType::ISFJ:
		return "ISFJ";
	case EPersonalityType::ENTP:
		return "ENTP";
	case EPersonalityType::ISFP:
		return "ISFP";
	}
}

void PersonalityType::DisplayOptions() {
	for (int i = 1; i <= NUM_OF_OPTIONS; i++) {
		std::cout << i << "." << ToString(EPersonalityType(i)) << std::endl;
	}
}