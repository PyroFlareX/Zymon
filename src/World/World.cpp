#include "World.h"

World::World()
{
	mapData = getJsonFile("res/Maps/Overworld.json");

	std::vector<int> tiles = mapData.at("layers").at(0).at("data");

	int tile[1850];
	int j = 0;
	for (int i : tiles)
	{
		tile[j] = i - 1;
		++j;
	}
	tiles.empty();
	tiles.~vector();

	if (!tilemap.load("res/Textures/tileset.png", sf::Vector2u(48, 48), tile, 50, 37))
	{
		std::cout << "In World File\n";
	}
}

World::~World()
{
    //dtor
}
