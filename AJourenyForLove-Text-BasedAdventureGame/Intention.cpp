#include "Intention.h"

std::string Intention::ToString(EIntention h) {
	switch (h) {
	case EIntention::Fling:
		return "Fling";
	case EIntention::Chat:
		return "Chat";
	case EIntention::Friendship:
		return "Friendship";
	case EIntention::Casual:
		return "Casual Dating";
	case EIntention::Partnership:
		return "Committed Partnership";
	}
}

void Intention::DisplayOptions() {
	for (int i = 1; i <= NUM_OF_OPTIONS; i++) {
		std::cout << i << "." << ToString(EIntention(i)) << std::endl;
	}
}