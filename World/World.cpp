#include "World.h"

World::World()
{
    level.setFillColor(sf::Color::Green);
    level.setSize(sf::Vector2<float>(1200.0f, 200.0f));
    level.setPosition(0.0f, 500.0f);
}

World::~World()
{
    //dtor
}

void World::update(sf::RenderWindow* window)
{
    window->draw(level);
}
