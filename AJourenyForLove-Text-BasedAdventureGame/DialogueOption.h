#pragma once
#include<string>

const int NUM_OF_DIALOGUE_OPTIONS = 5;

enum class DialogueOption {
	statement = 1,
	question,
	answer,
	sayNothing,
	exitConversation
};

std::string DialogueOptionToString (DialogueOption d);


