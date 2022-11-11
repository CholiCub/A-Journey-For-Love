#include"BodyType.h"

string BodyTypeToString(BodyType b) {
	switch (b) {
	case Thin:
		return "Thin";
	case Athletic:
		return "Athletic";
	case Average:
		return "Average";
	case AFewExtra:
		return "A Few Extra Pounds";
	case BigTallOrBBW:
		return "Big / Tall or BBW";
	}
}
