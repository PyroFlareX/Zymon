#include "Context.h"
#include <iostream>

Context::Context()
{
    sf::ContextSettings settings;
    context.create(sf::VideoMode(800, 600), "Vinegar", sf::Style::Default, settings);
    context.setFramerateLimit(60);
    initAPI();
}

Context::~Context()
{
    //context.close();
}

sf::RenderWindow* Context::getContext()
{
    return &context;
}

void Context::clear()
{
    context.clear(sf::Color::Black);
}

void Context::update()
{
    context.display();
}

void Context::draw()
{

}

void Context::close()
{
	context.close();
}

void Context::initAPI()
{

}
bool Context::isOpen()
{
    return context.isOpen();
}
