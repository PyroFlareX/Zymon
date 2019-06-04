#pragma once

#include "Zymon.h"
#include "Move.h"

class Battle
{
public:
	Battle();

	void doTurn();
	void waitForSelection();
	void nextTurn();

	bool isSelected();
	bool checkEnd();

	Zymon player[6];
	Zymon opponent[6];

	Move playerMove;
	Move opponentMove;
	int turn;

	bool isTrainerBattle;

	~Battle();
private:

};

