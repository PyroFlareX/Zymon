#include "Move.h"


Move::Move(int typepass, int PPpass, const std::string namepass, int powerpass, int accuracypass)
{
	type = typepass;
	PP = PPpass;
	name = namepass;
	power = powerpass;
	accuracy = accuracypass;
}

int Move::useMove(int Type1, int Type2)
{
	Random rand;
	if (accuracy >= rand.intInRange(1, 100))
	{
		--PP;

		int damage = power;
		//Do damage logic here
		//Function returns the amount of damage the move should deal to the opposing Zymon
		return damage;
	}
	else
	{
		return 0;
	}
}

Move::~Move()
{

}