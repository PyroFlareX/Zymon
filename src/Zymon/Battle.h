#pragma once

#include "Zymon.h"
#include "Move.h"

class Battle
{
public:
	Battle();

	void update() {};
	void getSelections(Move playerMove) {};

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
	void doTurn();
	void waitForSelection();
	void nextTurn();
};

