#include "Application.h"

#include "States/Gamestate.h"
#include "Util/FileUtil.h"


Application::Application()
{
    pushState<GameState>(*this);
}

void Application::RunLoop()
{
	sf::Clock timer;
	sf::Time dt;
	float t = 0;
	int frames = 0;

	m_context.clear();
	m_context.update();

    sf::RenderWindow* p_window = m_context.getContext();
    while(m_context.isOpen())
    {
		dt = timer.restart();
        ///Main Loop, do cycle of Input, Update, Draw, Render & Swap Buffers, Handle Events
        m_context.clear();
        ///Input
        currentState().input(p_window);

        /// Update
        currentState().update(&m_renderer);

        /// Draw
		m_renderer.render(p_window);

        /// Render
        m_context.update();

        /// Handle Window Events
		t += timer.getElapsedTime().asSeconds();
		frames++;
		if (t >= 1)
		{
			std::cout << frames << " per sec\n";
			t = 0;
			frames = 0;
		}
    }
}

void Application::popState()
{
    m_states.pop_back();
}

Basestate& Application::currentState()
{
    return *m_states.back();
}

void Application::handleEvents()
{
 /*   sf::Event e;
    while(window.pollEvent(e))
        {
        switch(e.type)
        {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::KeyPressed:
            switch(e.key.code)
            {
                case sf::Keyboard::Escape:
                    window.close();
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
        }
    }
*/
}
