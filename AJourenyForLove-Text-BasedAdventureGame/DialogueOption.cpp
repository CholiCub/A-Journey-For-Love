#include "DialogueOption.h"

std::string DialogueOptionToString(DialogueOption d) {
	switch (d) {
	case DialogueOption::statement:
		return "Statement";
	case DialogueOption::question:
		return "Question";
	case DialogueOption::answer:
		return "Answer";
	case DialogueOption::sayNothing:
		return "Say Nothing";
	case DialogueOption::exitConversation:
		return "Exit Conversation";
	}
}
