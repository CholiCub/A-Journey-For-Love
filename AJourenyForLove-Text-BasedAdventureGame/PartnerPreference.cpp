#include "PartnerPreference.h"
string PartnerPreferenceToString(PartnerPreference pp) {
	switch (pp) {
	case PartnerPreference::male:
		return "Male";
	case PartnerPreference::female:
		return "Female";
	case PartnerPreference::both:
		return "Both male and female";
	}
}