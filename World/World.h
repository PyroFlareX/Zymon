#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

class World
{
    public:
        World();

        sf::RectangleShape level;
        void update(sf::RenderWindow* window);

        ~World();
    protected:

    private:
};

#endif // WORLD_H
