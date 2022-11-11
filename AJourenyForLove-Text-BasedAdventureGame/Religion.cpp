#include "Religion.h"
string ReligionToString(Religion r) {
	switch (r) {
	case Religion::NonReligious:
		return "Non-Religious";
	case Religion::Anglican:
		return "Anglican";
	case Religion::Baptist:
		return "Baptist";
	case Religion::Buddhist:
		return "Buddhist";
	case Religion::Catholic:
		return "Catholic";
	case Religion::ChristianOther:
		return "Christian-Other";
	case Religion::EasternOrthdox:
		return "Eastern Orthodox";
	case Religion::Hindi:
		return "Hindi";
	case Religion::Jewish:
		return "Jewish";
	case Religion::Lutheran:
		return "Lutheran";
	case Religion::Methodist:
		return "Methodist";
	case Religion::Mormon:
		return "Mormon";
	case Religion::Muslim:
		return "Muslim";
	case Religion::Presbyterian:
		return "Prebyterian";
	case Religion::Spiritual:
		return "Spiritual";
	case Religion::Other:
		return "Other";
	}
}
