#pragma once
#include "Player.h"
#include "Date.h"

enum class EStage {
	Greeting = 0,
	Introduction,
	Conversation,
	Conculusion
};

enum class EConversationOptions{
	Talk = 0,
	Ask,
	Listen,
	Think
};

class Dialogue {
	Player player;
	Date date;
public:
	Dialogue(Player player, Date date) : player(player), date(date) {};
};

