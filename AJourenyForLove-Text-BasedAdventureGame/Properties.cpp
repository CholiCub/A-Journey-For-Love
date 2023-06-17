#include "Properties.h"

bool Properties::IsValidIntInEnum(int playerInput) {
	if (playerInput > 0 && playerInput <= NUM_OF_OPTIONS) return true;
	else return false;
}

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
