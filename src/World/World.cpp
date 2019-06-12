#include "World.h"

constexpr int MAP_HEIGHT = 37;
constexpr int MAP_WIDTH = 50;

World::World()
{
	mapData = getJsonFile("res/Maps/Overworld.json");

	std::vector<int> tiles = mapData.at("layers").at(0).at("data");

	int tile[MAP_HEIGHT * MAP_WIDTH];
	int j = 0;
	for (int i : tiles)
	{
		tile[j] = i - 1;
		++j;
	}

	if (!layer1.load("res/Textures/tileset.png", sf::Vector2u(48, 48), tile, MAP_WIDTH, MAP_HEIGHT))
	{
		std::cout << "In World File\n";
	}

	std::vector<int> tiles2 = mapData.at("layers").at(1).at("data");

	int tile2[MAP_HEIGHT * MAP_WIDTH ];
	j = 0;
	for (int i : tiles2)
	{
		if (i == 0) { i = 133; }
		//else {bounds.push_back(sf::FloatRect(sf::Vector2f(), sf::Vector2f(48, 48))) }
		tile2[j] = i - 1;
		++j;
	}

	if (!layer2.load("res/Textures/tilesetz.png", sf::Vector2u(48, 48), tile2, MAP_WIDTH, MAP_HEIGHT))
	{
		std::cout << "In World File\n";
	}

	
	tiles.clear();
	tiles2.clear();
}

/*std::vector<sf::FloatRect> World::getBounds()
{
	return bounds;
}*/

World::~World()
{
    //dtor
}
