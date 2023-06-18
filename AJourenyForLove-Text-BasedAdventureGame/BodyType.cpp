#include"BodyType.h"

std::string BodyType::ToString(EBodyType b) {
	switch (b) {
	case EBodyType::Thin:
		return "Thin";
	case EBodyType::Athletic:
		return "Athletic";
	case EBodyType::Average:
		return "Average";
	case EBodyType::AFewExtra:
		return "A Few Extra Pounds";
	case EBodyType::BigTallOrBBW:
		return "Big / Tall or BBW";
	}
}

void BodyType::DisplayOptions() {
	for (int i = 1; i <= NUM_OF_OPTIONS; i++) {
		std::cout << i << "." << ToString(EBodyType(i)) << std::endl;
	}
}