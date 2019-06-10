#pragma once

#include <SFML/Graphics.hpp>

struct Collision
{
	Collision(const int* collisionTiles);

	sf::FloatRect getBounds() {};
};
