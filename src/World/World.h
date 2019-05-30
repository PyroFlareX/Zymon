#ifndef WORLD_H
#define WORLD_H

#include "TileMap.h"
#include <iostream>

class World
{
    public:
        World();

		TileMap tilemap;

        ~World();
    protected:

    private:
};

#endif // WORLD_H
