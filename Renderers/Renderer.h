#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Renderer
{
    public:
        Renderer();

		void addDraw(sf::Drawable& drawable);
		void render(sf::RenderWindow* window);

        ~Renderer();
    protected:

    private:
		std::vector<sf::Drawable*> m_queue;
};

#endif // RENDERER_H
