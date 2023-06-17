#include "Race.h"

std::string Race::ToString(ERace r) {
	switch (r) {
	case ERace::AfricanAmerican:
		return "African American";
	case ERace::Asian:
		return "Asian";
	case ERace::Caucasian:
		return "Caucasian";
	case ERace::Black:
		return "Black";
	case ERace::Indian:
		return "Indian";
	case ERace::IndigenousOrAboriginal:
		return "Indigenous / Aboriginal";
	case ERace::LatinOrHispanic:
		return "Latin / Hispanic";
	case ERace::MiddleEastern:
		return "Middle Eastern";
	case ERace::Mixed:
		return "Mixed";
	case ERace::Other:
		return "Other";
	}
}

void Race::DisplayOptions() {
	for (int i = 1; i <= NUM_OF_OPTIONS; i++) {
		std::cout << i << "." << ToString(ERace(i)) << std::endl;
	}
}