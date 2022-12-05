#pragma once
#include "Player.h"
#include "Date.h"

enum Stage {
	greeting = 0,
	introduction,
	closing
	};

class Dialogue {
private:
	Player player;
	Date date;
public:
	/*Dialogue(Player player, Date date, DialogueOptions DialogueOptions);

	void SetDialogueOptions(DialogueOptions dialogueOptions);
	DialogueOptions GetDialogueoptions();

	void SetStageOfDialogue(Stage stageOfDialogue);
	Stage GetStageOfDialogue;*/
};

