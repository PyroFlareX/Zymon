#pragma once

#include <string>

enum Types
{
	FIRE,
	WATER,
	GRASS,
	FIGHTING,
	ELECTRIC,
	AIR,
	EARTH,
	GHOST,
	PSYCIC,
	NORMAL,
	DARK,
	METAL,
	TOXIC,
	ROCK,
	BUG,
	none
};

struct StatsBase
{
	int HP;
	int Atk;
	int Def;
	int SpecialAtk;
	int SpecialDef;
	int Speed;
	int Level;
};

struct EVs
{
	int HP;
	int Atk;
	int Def;
	int SpecialAtk;
	int SpecialDef;
	int Speed;
};

struct IVs
{
	int HP;
	int Atk;
	int Def;
	int SpecialAtk;
	int SpecialDef;
	int Speed;
};

class Zymon
{
public:
	Zymon();

	std::string nickname;
	int Type[2] = { Types::none };
	int statusCondition = 0;

	StatsBase stats;
	EVs EV;
	IVs IV;

	~Zymon();
protected:
	unsigned int dexID;
	
};

