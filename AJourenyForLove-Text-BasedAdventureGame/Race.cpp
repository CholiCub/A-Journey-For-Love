#include "Race.h"

string RaceToString(ERace r) {
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
