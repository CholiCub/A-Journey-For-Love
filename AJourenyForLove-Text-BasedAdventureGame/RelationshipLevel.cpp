#include "RelationshipLevel.h"

std::string RelationshipLevel::ToString(ERelationshipLevel h) {
	switch (h) {
	case ERelationshipLevel::Stranger:
		return "Stranger";
	case ERelationshipLevel::Relevant:
		return "Relevant";
	case ERelationshipLevel::Friend:
		return "Friend";
	case ERelationshipLevel::Like:
		return "Like";
	case ERelationshipLevel::Love:
		return "Love";
	case ERelationshipLevel::Adore:
		return "Adore";
	}
}

void RelationshipLevel::DisplayOptions() {
	for (int i = 1; i <= NUM_OF_OPTIONS; i++) {
		std::cout << i << "." << ToString(ERelationshipLevel(i)) << std::endl;
	}
}