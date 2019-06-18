#include "Application.h"

#include "States/Gamestate.h"
#include "States/BattleState.h"
#include "Util/FileUtil.h"


Application::Application()
{
	pushState(std::make_unique<GameState>());
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
	Camera cam(p_window);
    while(m_context.isOpen() && !m_states.empty())
    {
		dt = timer.restart();
        ///Main Loop, do cycle of Input, Update, Draw, Render & Swap Buffers, Handle Events
        m_context.clear();
        ///Input
		if (currentState().input(*this))
		{

		}

        /// Update
        currentState().update(p_window, dt.asSeconds());
		currentState().lateUpdate(&cam);

        /// Draw
		currentState().render(&m_renderer);
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

		handleEvents();
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
    sf::Event e;
	sf::View v;
    while(m_context.getContext()->pollEvent(e))
        {
        switch(e.type)
			{
			case sf::Event::Closed:
				m_context.close();
				break;

			case sf::Event::Resized:
				// update the view to the new size of the window
				v = m_context.getContext()->getView();
				v.setSize(e.size.width, e.size.height);
				m_context.getContext()->setView(v);

			case sf::Event::KeyPressed:
				switch(e.key.code)
				{
				    case sf::Keyboard::Escape:
						m_context.close();
					    break;

	                default:
		                break;
            }
            break;

        default:
            break;
        }
    }

}
