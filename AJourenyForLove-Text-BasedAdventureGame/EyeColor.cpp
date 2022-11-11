#include "EyeColor.h"

string EyeColorToString(EyeColor e) {
	switch (e) {
	case EyeColor::Brown:
		return "Brown";
	case EyeColor::Green:
		return "Green";
	case EyeColor::Blue:
		return "Blue";
	case EyeColor::Hazel:
		return "Hazel";
	case EyeColor::Other:
		return "Other";
	}
}
