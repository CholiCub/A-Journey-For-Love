#include "EyeColor.h"

string EyeColorToString(EEyeColor e) {
	switch (e) {
	case EEyeColor::Brown:
		return "Brown";
	case EEyeColor::Green:
		return "Green";
	case EEyeColor::Blue:
		return "Blue";
	case EEyeColor::Hazel:
		return "Hazel";
	case EEyeColor::Other:
		return "Other";
	}
}
