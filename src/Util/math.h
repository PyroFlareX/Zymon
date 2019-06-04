#pragma once

#include <SFML/System.hpp>

inline sf::Vector2f lerp(sf::Vector2f current, sf::Vector2f target, float gradient)
{
	return sf::Vector2f((target - current) * gradient + current);
}
