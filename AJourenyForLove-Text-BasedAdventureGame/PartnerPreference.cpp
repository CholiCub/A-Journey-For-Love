#include "PartnerPreference.h"
string PartnerPreferenceToString(EPartnerPreference pp) {
	switch (pp) {
	case EPartnerPreference::male:
		return "Male";
	case EPartnerPreference::female:
		return "Female";
	case EPartnerPreference::both:
		return "Both male and female";
	}
}