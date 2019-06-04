#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();

	sf::Sprite Character;

	sf::FloatRect getBounds();
	void updateDirection(int direction);

	~Player();
private:
	sf::Image sheet;
	sf::Texture tex;
	int facingDir;
	float tileSteps;
};

