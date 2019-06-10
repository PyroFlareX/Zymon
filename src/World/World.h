#ifndef WORLD_H
#define WORLD_H

#include "TileMap.h"
#include <iostream>

#include "../Util/FileUtil.h"

class World
{
    public:
        World();

		TileMap layer1;
		TileMap layer2;
		

        ~World();
    protected:

    private:
		nlohmann::json mapData;
};

#endif // WORLD_H
