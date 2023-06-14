#include "Properties.h"

int Properties::GetPlayerSettings(){
	int num = {};
	do {
		DisplayOptions();
		std::cin >> num;
		if (!IsValidIntInEnum(num)) {
			std::cout << "Invalid entry. Try again." << std::endl << std::endl;
		}
	} while (!IsValidIntInEnum(num));
	return num;
}
