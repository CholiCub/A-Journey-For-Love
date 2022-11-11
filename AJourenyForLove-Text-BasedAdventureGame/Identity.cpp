#include "Identity.h"

string IdentityToString(Identity i) {
	switch (i) {
	case Identity::Man:
		return "Man";
	case Identity::Woman:
		return "Woman";
	case Identity::CisWoman:
		return "Cis Woman";
	case Identity::TransWoman:
		return "Trans Woman";
	case Identity::CisMan:
		return "Cis Man";
	case Identity::TransMan:
		return "Trans Man";
	case Identity::NonBinary:
		return "Non-Binary";
	}
}
