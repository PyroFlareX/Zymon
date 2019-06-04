#pragma once

#include <string>

class Move
{
public:
	Move();

	int power;
	int accuracy;
	int PP;

	int type;

	std::string name;

	~Move();
private:

};

