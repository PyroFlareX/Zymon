#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Renderer
{
    public:
        Renderer();

		void addDraw(sf::Sprite& drawable);
		void render(sf::RenderWindow* window);

        ~Renderer();
    protected:

    private:
		std::vector<sf::Sprite> m_queue;
};

#endif // RENDERER_H
