#include "Identity.h"

std::string Identity::ToString(EIdentity i) {
	switch (i) {
	case EIdentity::Man:
		return "Man";
	case EIdentity::Woman:
		return "Woman";
	case EIdentity::CisWoman:
		return "Cis Woman";
	case EIdentity::TransWoman:
		return "Trans Woman";
	case EIdentity::CisMan:
		return "Cis Man";
	case EIdentity::TransMan:
		return "Trans Man";
	case EIdentity::NonBinary:
		return "Non-Binary";
	}
}

void Identity::DisplayOptions() {
	for (int i = 1; i <= NUM_OF_OPTIONS; i++) {
		std::cout << i << "." << ToString(EIdentity(i)) << std::endl;
	}
}
