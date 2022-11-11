#include "Race.h"

string RaceToString(Race r) {
	switch (r) {
	case Race::AfricanAmerican:
		return "African American";
	case Race::Asian:
		return "Asian";
	case Race::Caucasian:
		return "Caucasian";
	case Race::Black:
		return "Black";
	case Race::Indian:
		return "Indian";
	case Race::IndigenousOrAboriginal:
		return "Indigenous / Aboriginal";
	case Race::LatinOrHispanic:
		return "Latin / Hispanic";
	case Race::MiddleEastern:
		return "Middle Eastern";
	case Race::Mixed:
		return "Mixed";
	case Race::Other:
		return "Other";
	}
}
