#include "World.h"

World::World()
{
	int level[1850];

	for (int i = 0; i < 1850; ++i)
	{
		level[i] = 52;
	}

	if (!tilemap.load("res/Textures/tileset.png", sf::Vector2u(24, 24), level, 50, 37))
	{
		std::cout << "In World File\n";
	}
}

World::~World()
{
    //dtor
}
