#pragma once

#include "Zymon.h"
#include <string>
#include "../Util/Random.h"

struct Move
{
public:
	Move() {};
	Move(int typepass, int PPpass, const std::string namepass, int powerpass, int accuracypass);

	int useMove(int Type1, int Type2);

	int power;
	int accuracy;
	int PP;

	int type;

	std::string name;

	~Move();
};
