#include "Battle.h"


Battle::Battle()
{

}

void Battle::doTurn()
{
	if (player[0].stats.Speed >= opponent[0].stats.Speed)
	{
		opponent[0].stats.HP -= playerMove.power * player[0].stats.Atk;
		player[0].stats.HP -= opponentMove.power * opponent[0].stats.Atk;
	}
	else
	{
		player[0].stats.HP -= opponentMove.power * opponent[0].stats.Atk;
		opponent[0].stats.HP -= playerMove.power * player[0].stats.Atk;
	}
	nextTurn();
}

void Battle::waitForSelection()
{

}

void Battle::nextTurn()
{
	turn++;
}

bool Battle::isSelected()
{
	return false;
}

Battle::~Battle()
{

}
