#include "GameState.h"

#include <iostream>

GameState::GameState(Application& app)
: Basestate(app)
{
	
}

GameState::~GameState()
{

}

void GameState::input(sf::RenderWindow* window)
{
	moveOffset = sf::Vector2f(0.f, 0.f);

	Input::Inputs input = Input::getInput();

    if(input.right)
    {
        std::cout << "Going Right!\n";
        moveOffset.x += 48.0f;
		m_player.updateDirection(0);
    }
    if(input.left)
    {
        std::cout << "Going Left!\n";
        moveOffset.x -= 48.0f;
		m_player.updateDirection(1);
    }
    if(input.up)
    {
        std::cout << "Going Up!\n";
    }
    if(input.down)
    {
        std::cout << "Going Down!\n";
    }
    if(input.forth)
    {
        std::cout << "Going Forward!\n";
		moveOffset.y -= 48.0f;
		m_player.updateDirection(2);
    }
    if(input.backwards)
    {
        std::cout << "Going Back!\n";
		moveOffset.y += 48.0f;
		m_player.updateDirection(3);
    }

	m_player.Character.move(moveOffset);
	sf::View view(window->getView());
	view.setCenter(m_player.Character.getPosition() + sf::Vector2f(0.0f , 48.0f));
	window->setView(view);
}

void GameState::update(Renderer* renderer)
{
	std::cout << "Position of Player: " << m_player.Character.getPosition().x / 48 << " " << m_player.Character.getPosition().y / 48 << "\n";
	renderer->addDraw(map.tilemap);
	renderer->addDraw(m_player.Character);
}
