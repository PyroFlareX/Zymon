#pragma once

#include <SFML/Graphics.hpp>
#include "Zymon/Zymon.h"

class Player
{
public:
	Player();

	sf::Sprite Character;

	sf::FloatRect getBounds();
	void updateDirection(int direction);

	Zymon zyTeam[6];

	~Player();
private:
	sf::Image sheet;
	sf::Texture tex;
	int facingDir;
	float tileSteps;
};

