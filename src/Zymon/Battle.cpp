#include "Battle.h"


Battle::Battle()
{
	player[0].Type[0] = Types::NORMAL;
	player[0].Type[1] = Types::none;
	player[0].stats.Atk = 12;
	player[0].stats.Def = 10;
	player[0].stats.HP = 20;
	player[0].stats.Speed = 10;
	opponent[0].stats.Def = 5;
	opponent[0].stats.HP = 100;
}

void Battle::update()
{
	waitForSelection();
	if(isSelected())
	{
		doTurn();
	}
}

void Battle::getSelections(Move inMove)
{
	if (!isSelected())
	{
		moveQueue.push_back(inMove);
		playerMove = inMove;
	}
}

bool Battle::doTurn()
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
	return true;
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
	if (!moveQueue.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Battle::checkEnd()
{
	bool faint = (opponent[0].stats.HP <= 0) || (player[0].stats.HP <= 0);
	if (faint)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Battle::~Battle()
{

}
