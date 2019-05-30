#include "Renderer.h"

Renderer::Renderer()
{
    //ctor
}

void Renderer::addDraw(sf::Sprite& drawable)
{
	m_queue.push_back(drawable);
}

void Renderer::render(sf::RenderWindow* window)
{
	for (auto& item : m_queue)
	{
		window->draw(item);
	}
	m_queue.clear();
}

Renderer::~Renderer()
{
    //dtor
}
