#include "World.h"

World::World()
{
	int level[1850];

	for (int i = 0; i < 1850; ++i)
	{
		level[i] = 17;
	}

	if (!tilemap.load("res/Textures/tileset.png", sf::Vector2u(48, 48), level, 50, 37))
	{
		std::cout << "In World File\n";
	}
}

World::~World()
{
    //dtor
}
