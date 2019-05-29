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
	unsigned int HP;
	unsigned int Atk;
	unsigned int Def;
	unsigned int SpecialAtk;
	unsigned int SpecialDef;
	unsigned int Speed;
	unsigned int Level;
};

struct EVs
{
	unsigned int HP;
	unsigned int Atk;
	unsigned int Def;
	unsigned int SpecialAtk;
	unsigned int SpecialDef;
	unsigned int Speed;
};

struct IVs
{
	unsigned int HP;
	unsigned int Atk;
	unsigned int Def;
	unsigned int SpecialAtk;
	unsigned int SpecialDef;
	unsigned int Speed;
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
private:
	unsigned int dexID;
	
};

