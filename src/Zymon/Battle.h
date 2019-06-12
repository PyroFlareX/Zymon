#pragma once

#include "Zymon.h"
#include "Move.h"
#include <vector>

class Battle
{
public:
	Battle();

	void update();
	void getSelections(Move inMove);

	bool isSelected();
	bool checkEnd();
	bool doTurn();

	Zymon player[6];
	Zymon opponent[6];

	Move playerMove;
	Move opponentMove;
	int turn;

	bool isTrainerBattle;

	~Battle();
private:
	std::vector<Move> moveQueue;

	void waitForSelection();
	void nextTurn();
};

