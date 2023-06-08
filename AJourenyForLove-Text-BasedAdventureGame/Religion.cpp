#include "Religion.h"
string ReligionToString(EReligion r) {
	switch (r) {
	case EReligion::NonReligious:
		return "Non-Religious";
	case EReligion::Anglican:
		return "Anglican";
	case EReligion::Baptist:
		return "Baptist";
	case EReligion::Buddhist:
		return "Buddhist";
	case EReligion::Catholic:
		return "Catholic";
	case EReligion::ChristianOther:
		return "Christian-Other";
	case EReligion::EasternOrthdox:
		return "Eastern Orthodox";
	case EReligion::Hindi:
		return "Hindi";
	case EReligion::Jewish:
		return "Jewish";
	case EReligion::Lutheran:
		return "Lutheran";
	case EReligion::Methodist:
		return "Methodist";
	case EReligion::Mormon:
		return "Mormon";
	case EReligion::Muslim:
		return "Muslim";
	case EReligion::Presbyterian:
		return "Prebyterian";
	case EReligion::Spiritual:
		return "Spiritual";
	case EReligion::Other:
		return "Other";
	}
}
