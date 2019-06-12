#include "Battle.h"


Battle::Battle()
{

}

void Battle::update()
{
	waitForSelection();
	if(isSelected())
	{
		doTurn();
	}
}

void Battle::getSelections(Move playerMove)
{
	moveQueue.push_back(playerMove);
}

void Battle::doTurn()
{
	if (player[0].stats.Speed >= opponent[0].stats.Speed)
	{
		opponent[0].stats.HP -= playerMove.useMove(opponent[0].Type[0], opponent[0].Type[1]) * player[0].stats.Atk / opponent[0].stats.Def;
		player[0].stats.HP -= opponentMove.useMove(player[0].Type[0], player[0].Type[1]) * opponent[0].stats.Atk / player[0].stats.Def;
	}
	else
	{
		player[0].stats.HP -= opponentMove.useMove(player[0].Type[0], player[0].Type[1]) * opponent[0].stats.Atk / player[0].stats.Def;
		opponent[0].stats.HP -= playerMove.useMove(opponent[0].Type[0], opponent[0].Type[1]) * player[0].stats.Atk / opponent[0].stats.Def;
	}
	nextTurn();
}

void Battle::waitForSelection()
{

}

void Battle::nextTurn()
{
	moveQueue.clear();
	turn++;
}

bool Battle::isSelected()
{
	if (true)
	{
		return false;
	}
}

bool Battle::checkEnd()
{
	return false;
}

Battle::~Battle()
{

}
