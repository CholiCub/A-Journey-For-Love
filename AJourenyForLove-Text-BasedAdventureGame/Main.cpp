#include<iostream>
#include<string>
#include <iterator> 
#include "Identity.h"
#include "Race.h"
#include "BodyType.h"
#include "Religion.h"
#include "HairColor.h"
#include "EyeColor.h"
#include "PartnerPreference.h"
#include "Player.h"
#include "Date.h"
#include "DialogueOption.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

void ToUpper(string& oldString);
void GetPlayerJournalSetting();
bool IsValidIntInEnum(const int numOfItems, int playerInput);
template <class myType> void PrintOptions(const int numOfOptions, string(*s)(myType));
bool ReturningPlayer(Player p);
const string defaultPlayerJournalSettingsFile = "PlayerJournalSettings.json";
const string QUOTE_DELIMITER = "\"";
bool IsFileEmpty(ifstream& pFile);
void Game();
void Introduction(Date date);
void PrintDialogueOptions(map<int, string>& options);
void PrintCategoryOptions(map<string, string>& options);
void DeleteElementFromMap(map<string, string>& options, const int num);
void DeleteElementFromMapIntNString(map<int, string>& options, const int num);
Player player{};
json j;

int main() {

	Identity identity{};
	Race race{};
	BodyType bodyType{};
	Religion religion{};
	HairColor hairColor{};
	EyeColor eyeColor{};
	PartnerPreference partnerPreference{};
	int age{};
	char dash{};
	int heightInInches{}, bodyTypeNum{};
	int likeAnimals{};
	bool identityValid{};

	if (ReturningPlayer(player)) {
		std::cout << "Welcome back to A Journey for Love" << endl;
		player.PrintPlayerInfo();
	}
	else {
		std::cout << "Welcome to A Journey for Love" << endl;
		GetPlayerJournalSetting();
	}
	Game();

	std::cout << "\n\nThank you for playing!" << endl;
}

void ToUpper(string& oldString) {
	getline(std::cin, oldString);
	for (int i = 0; i < oldString.length(); i++) {
		oldString[i] = toupper(oldString[i]);
	}
}

void GetPlayerJournalSetting() {
	bool playerInputValid{ };
	string name{};
	int age{};
	int identityNum{}, raceNum{}, bodyTypeNum{}, religionNum{}, hairColorNum{}, eyeColorNum{}, partnerPreferenceNum{};
	bool IsIdenityValid{};
	bool IsRaceValid{};
	bool IsBodyTypeValid{};
	bool IsReligionValid{};
	bool IsEyeColorValid{};
	bool IsHairColorValid{};
	bool IsPartnerPreferenceValid{};

	std::cout << "\nEnter first name: ";
	getline(std::cin, name);

	do {
		std::cout << "Enter age: ";
		cin >> age;
	} while (!(age >= 18 && age < 105));

	do {
		std::cout << "Enter the identity you best identify with: " << endl;
		PrintOptions(NUM_OF_IDENTITIES, IdentityToString);
		std::cin >> identityNum;
		IsIdenityValid = IsValidIntInEnum(NUM_OF_IDENTITIES, identityNum);
		if (!IsIdenityValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsIdenityValid);
	do {
		std::cout << "Enter the race you best identify with: " << endl;
		PrintOptions(NUM_OF_RACES, RaceToString);
		std::cin >> raceNum;
		IsRaceValid = IsValidIntInEnum(NUM_OF_RACES, raceNum);
		if (!IsRaceValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsRaceValid);
	do {
		std::cout << "Enter the body type that best describes you: " << endl;
		PrintOptions(NUM_OF_BODY_TYPES, BodyTypeToString);
		std::cin >> bodyTypeNum;
		IsBodyTypeValid = IsValidIntInEnum(NUM_OF_BODY_TYPES, bodyTypeNum);
		if (!IsBodyTypeValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsBodyTypeValid);
	do {
		std::cout << "Enter the religion that best describes you: " << endl;
		PrintOptions(NUM_OF_RELIGION, ReligionToString);
		std::cin >> religionNum;
		IsReligionValid = IsValidIntInEnum(NUM_OF_RELIGION, religionNum);
		if (!IsBodyTypeValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsReligionValid);
	do {
		std::cout << "Enter your partner preference: " << endl;
		PrintOptions(NUM_OF_PARTNER_PREFERENCE, PartnerPreferenceToString);
		std::cin >> partnerPreferenceNum;
		IsPartnerPreferenceValid = IsValidIntInEnum(NUM_OF_PARTNER_PREFERENCE, partnerPreferenceNum);
		if (!IsPartnerPreferenceValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsPartnerPreferenceValid);
	do {
		std::cout << "Enter your eye color: " << endl;
		PrintOptions(NUM_OF_EYE_COLORS, EyeColorToString);
		std::cin >> eyeColorNum;
		IsEyeColorValid = IsValidIntInEnum(NUM_OF_EYE_COLORS, eyeColorNum);
		if (!IsEyeColorValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsEyeColorValid);
	do {
		std::cout << "Enter your hair color: " << endl;
		PrintOptions(NUM_OF_HAIR_COLORS, HairColorToString);
		std::cin >> hairColorNum;
		IsHairColorValid = IsValidIntInEnum(NUM_OF_HAIR_COLORS, hairColorNum);
		if (!IsHairColorValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsHairColorValid);

	Player createdPlayer(name, age, IdentityToString(Identity(identityNum)),
		RaceToString(Race(raceNum)), ReligionToString(Religion(religionNum)), BodyTypeToString(BodyType(bodyTypeNum)),
		HairColorToString(HairColor(hairColorNum)), EyeColorToString(EyeColor(eyeColorNum)),
		PartnerPreferenceToString(PartnerPreference(partnerPreferenceNum)));
	player = createdPlayer;
	//Create JSON file to store player data
	player.ToJson(j, player, defaultPlayerJournalSettingsFile);
	player.PrintPlayerInfo();

	std::cout << "\nThank you for entering your settings!" << endl;
}

template <class myType> void PrintOptions(const int numOfOptions, string(*s)(myType)) {
	for (int i = 1; i <= numOfOptions; i++) {
		std::cout << i << "." << s(myType(i)) << endl;
	}
}
template <class myType> void PrintSelectOptions(string(*s)(myType), list<int> list, map<int, string>& options) {
	int k{ 1 };
	for (int j : list) {
		options.insert(pair<int, string>(k, s(myType(j))));
		std::cout << k++ << "." << s(myType(j)) << endl;
	}
}

//template <class myType> void SelectOption(string(*s)(myType), list<int> list) {
//	int k{ 1 };
//	for (int j : list) {
//		std::cout << k++ << "." << s(myType(j)) << endl;
//	}
//}
//checks int num to number of items 
bool IsValidIntInEnum(const int numOfItems, int playerInput) {
	if (playerInput > 0 && playerInput <= numOfItems) {
		return true;
	}
	else return false;
}

bool ReturningPlayer(Player p) {
	ifstream ifs;
	ifs.open(defaultPlayerJournalSettingsFile);
	json j;
	if (!IsFileEmpty(ifs)) {
		player.FromJson(player, defaultPlayerJournalSettingsFile);
		ifs.close();
		return true;
	}
	else {
		ifs.close();
		return false;
	}
}
bool IsFileEmpty(ifstream& pFile) {
	return pFile.peek() == ifstream::traits_type::eof();
}
void Game() {

	Date tutorialDate("Sam", 30, "Trans Women", "Black", "Catholic", "Thin", "Black", "Brown", "Men", "Dominant", "Casual", "Stranger", 0);

	std::cout << "\nMatchmaker:" + QUOTE_DELIMITER + "You are going to be going on a date with " + tutorialDate.getName() + QUOTE_DELIMITER + "\n";
	std::cout << "\nScene\n-----" << endl;
	std::cout << "You walk into the restaurant and see your date sitting at the table" << endl;
	std::cout << "Their " + tutorialDate.getHairColor() + " hair shimmering by the lamp above and their " + tutorialDate.getEyeColor() +
		" eyes staring up at you. You notice they appear to be of " + tutorialDate.getRace() + " decendants and " + tutorialDate.getBodyType() + ".\n";
	std::cout << "You sit down at the table with them." << endl;
	std::cout << "--Conversation Start--" << endl;

	std::cout << "\n" + tutorialDate.getName() + ":" + QUOTE_DELIMITER + "Hi, I'm " + tutorialDate.getName() + QUOTE_DELIMITER + "\n\n";

	list<int> greetingOptions{ 1 };
	map<int, string> options;

	std::cout << "list number" << greetingOptions.size() << endl;
	int greetingOptionNum{};
	bool IsDialogueOptionValid{};
	do {
		std::cout << "Choose an option: " << endl;

		PrintSelectOptions(DialogueOptionToString, greetingOptions, options);
		std::cin >> greetingOptionNum;
		IsDialogueOptionValid = IsValidIntInEnum(greetingOptions.size(), greetingOptionNum);

		if (!IsDialogueOptionValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsDialogueOptionValid);
	std::cout << endl;
	//Handle Statement - name formal and informal
	map<int, string> nameOptions;
	int optionNum{ 1 };
	string formal{ "Hello my name is " + player.getName() };
	string informal{ "Hey I'm " + player.getName() };
	nameOptions.insert(pair<int, string>(optionNum++, formal));
	nameOptions.insert(pair<int, string>(optionNum++, informal));
	//take player selection
	bool IsNameGreetingDialogueOptionValid{};
	int greetingNameOptionNum;
	do {
		std::cout << "Choose an option: " << endl;
		PrintDialogueOptions(nameOptions);
		cin >> greetingNameOptionNum;
		IsNameGreetingDialogueOptionValid = IsValidIntInEnum(nameOptions.size(), greetingNameOptionNum);
		if (!IsNameGreetingDialogueOptionValid) {
			std::cout << "Invalid entry. Try again." << endl << endl;
		}
	} while (!IsNameGreetingDialogueOptionValid);

	std::cout << "\n" + tutorialDate.getName() + ":" + QUOTE_DELIMITER + "Nice to meet you " + player.getName() + QUOTE_DELIMITER + "\n\n";
	Introduction(tutorialDate);
}
void Introduction(Date date) {
	//Introduction stage
	//Intro dialogue options
	list<int> introductionOptions{ 1,2,4,5 };
	//specific categories option
	map<int, string> introOptions;

	//player categories
	map<string, string> playerCategories = { {"Religion", player.getReligion()},
											{"Partner Preference",player.getPartnerPreference()} };
	//ai categories
	string ageToString = to_string(date.getAge());
	map<string, string> dateCategories = { {"Age", ageToString},
											{"Identity",date.getIdentity()},
											{"Race",date.getRace()},
											{"Religion", date.getReligion()},
											{"Partner Preference",date.getPartnerPreference()} };

	map<int, string> conversationReport;

	//random turn assignment
	int turn = 1;
	int dateDialogueOption{};
	int chatPingPing{};

	//statement - category dialogue optiuons
	int optionNum{ 1 };
	bool IsCategoryOptionValid{};
	int catNum{};
	//options
	list<int> ppCategories;
	string pp1{ "What is your partner preference? " };
	string pp2{ "Do you normally date men, women or both" };

	int introOptionNum{};
	bool IsIntroDialogueOptionValid{};
	do {
		//player turn
		if (turn == 1) {
			std::cout << "(PLAYER TURN)---" << endl;
			//Display Dialogue Options (Statemnet, Question, Say Nothing, Exit Conversation)
				//Select Dialogue Option
					//switch case for dialogue options
					// (Statement - randomize who speaks after turn)
					// (Question - set next to speak to other player, IF NO category dialogues are available just send random communication (ex:um...... OR remove category from list)
					// (Say Nothing - set ai to speaks)
					// (Exit Conversartion - set ai to speaks,  count number of items in conversation list (ex: "0-"wow okay bye, "1-okay not much of a talker whatever" ETC)
					//Display Category options depending dialogue option (Statement - "",Question - "" , Say Nothing - "", Exit Conversation - "")
						//Select Category option
							//Display Category Dialogue Options
								//Select Category Dialogue Option

			//Display Dialogue Options (Statemnet, Question, Say Nothing, Exit Conversation)
			do {
				std::cout << "Choose an option: " << endl;
				//Select Dialogue Option
				/*if (playerCategories.size()==0) {
					DeleteElementFromMapIntNString(introOptions,introOptionNum);
				}*/
				PrintSelectOptions(DialogueOptionToString, introductionOptions, introOptions);
				std::cin >> introOptionNum;
				//Input Checking Dialogue Option 
				IsIntroDialogueOptionValid = IsValidIntInEnum(introOptions.size(), introOptionNum);
				if (!IsIntroDialogueOptionValid) {
					std::cout << "Invalid entry. Try again." << endl << endl;
				}
			} while (!IsIntroDialogueOptionValid);
			std::cout << endl;
			//Handle the Dialogue Option
			switch (introOptionNum) {
			case 1:
				//conversationReport.insert(std::pair<int, string>(turn, "Statement"));
				++chatPingPing;
				std::cout << "STATEMENT" << endl;
				turn = rand() % 2 + 1;
				dateDialogueOption = 1;

				//Handle Category Dialogue Options
				//take player selection
				do {
					std::cout << "Choose an option: " << endl;
					PrintCategoryOptions(playerCategories);
					cin >> catNum;
					IsCategoryOptionValid = IsValidIntInEnum(playerCategories.size(), catNum);
					if (!IsCategoryOptionValid) {
						std::cout << "Invalid entry. Try again." << endl << endl;
					}
				} while (!IsCategoryOptionValid);

				//Delete Category from map
				DeleteElementFromMap(playerCategories,catNum);
				//Display cat options (PP and Religion)


				break;
				//display statement - category options
				//then display specific category options
			case 2:
				++chatPingPing;
				//conversationReport.insert(std::pair<int, string>(turn, "Question"));
				std::cout << "QUESTION" << endl;
				turn = 5;
				dateDialogueOption = 1;
				break;
				//question
				//dislpay question categories that have not been discussed before
			case 3:
				//conversationReport.insert(std::pair<int, string>(turn, "Say Nothing"));
				std::cout << "SAY NOTHING" << endl;
				turn = 5;
				dateDialogueOption = 3;
				break;
				//Say Nothing
				//
			case 4:
				//conversationReport.insert(std::pair<int, string>(turn, "Exit"));
				turn = 5;
				dateDialogueOption = 4;
				break;
				//Exit Conversation
				//get counter to sure player isnt rude
			}
		}
		else
			//date goes
		{
			std::cout << "(DATE TURN)---" << endl;
			switch (dateDialogueOption) {
			case 1:
				std::cout << date.getName() + ":" + QUOTE_DELIMITER + "Date Statement " + QUOTE_DELIMITER + "\n";
				turn = rand() % 2 + 1;
				dateDialogueOption = 1;
				break;
				/*case 2:
				cout << "\n" + date.getName() + ":" + QUOTE_DELIMITER + "DATE question" + QUOTE_DELIMITER + "\n\n";
				break;*/
			case 3:
				std::cout << date.getName() + ":" + QUOTE_DELIMITER + "*sigh....." + QUOTE_DELIMITER + "\n\n";
				turn = rand() % 2 + 1;
				dateDialogueOption = 1;
				break;
			case 4:
				if (chatPingPing >= 3) {
					std::cout <<date.getName() + ":" + QUOTE_DELIMITER + "It was nice talking to you. We should do it again!" + QUOTE_DELIMITER + "\n\n";
				}
				else if (chatPingPing > 1 && chatPingPing <= 2) {
					std::cout <<date.getName() + ":" + QUOTE_DELIMITER + "Okay, well... bye." + QUOTE_DELIMITER + "\n\n";
				}
				else {
					std::cout <<date.getName() + ":" + QUOTE_DELIMITER + "Wow! You just got here and now your leaving, how rude!" + QUOTE_DELIMITER + "\n\n";
				}
				turn = 10;
				break;
			}
			//check current dialogue option
			/*switch () {
			default:
				break;
			}*/
			//int dateDialogueOption = rand() % 2 + 1;
		}
	} while (turn != 10);
	std::cout << "--Conversation Ended--" << endl;
	//report conversation summary

}
void PrintDialogueOptions(map<int, string>& options) {
	map<int, string>::iterator itr;
	for (itr = options.begin(); itr != options.end(); ++itr) {
		std::cout << itr->first << "." << itr->second << '\n';
	}
}
void PrintCategoryOptions(map<string, string>& options) {
	map<string, string>::iterator itr;
	int i{};
	for (itr = options.begin(); itr != options.end(); ++itr) {
		std::cout << ++i << "." << itr->first << '\n';
	}
}
void DeleteElementFromMap(map<string, string>& options, const int num) {
	map<string, string>::iterator itr;
	int i{};
	for (itr = options.begin(); itr != options.end(); ++itr) {
		++i;
		if (i == num) 			{
			options.erase(itr);
			break;
		}
	}
}
void DeleteElementFromMapIntNString(map<int, string>& options, const int num) {
	map<int, string>::iterator itr;
	int i{};
	for (itr = options.begin(); itr != options.end(); ++itr) {
		++i;
		if (i == num) {
			options.erase(itr);
			break;
		}
	}
}
void SetDialogueTurn(int turn = 0) {
	turn = 1;
}