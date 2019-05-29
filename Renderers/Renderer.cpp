#include "Renderer.h"

Renderer::Renderer()
{
    //ctor
}

void Renderer::addDraw(sf::Drawable& drawable)
{
	m_queue.push_back(&drawable);
}

void Renderer::render(sf::RenderWindow* window)
{
	for (sf::Drawable* item : m_queue)
	{
		window->draw(*item);
	}
}

Renderer::~Renderer()
{
    //dtor
}
