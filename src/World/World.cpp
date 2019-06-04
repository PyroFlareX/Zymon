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

	if (!layer1.load("res/Textures/tileset.png", sf::Vector2u(48, 48), tile, 50, 37))
	{
		std::cout << "In World File\n";
	}

	std::vector<int> tiles2 = mapData.at("layers").at(1).at("data");

	int tile2[1850];
	j = 0;
	for (int i : tiles2)
	{
		if (i == 0) { i = 133; }
		tile2[j] = i - 1;
		++j;
	}

	if (!layer2.load("res/Textures/tilesetz.png", sf::Vector2u(48, 48), tile2, 50, 37))
	{
		std::cout << "In World File\n";
	}

	tiles.clear();
	tiles.~vector();
	tiles2.clear();
	tiles2.~vector();
}

World::~World()
{
    //dtor
}
