#include "GameState.h"

#include <iostream>
#include "../Util/math.h"

GameState::GameState(Application& app)
: Basestate(app)
{
	wait = 0.0f;
}

GameState::~GameState()
{
	m_player.~Player();
}

void GameState::input()
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
}

void GameState::update(sf::RenderWindow* window, float dt)
{
	if (true)//!(m_player.getBounds().intersects(sf::FloatRect(sf::Vector2f(192, 192), sf::Vector2f(192, 192)))))
	{
		m_player.Character.setPosition(lerp(m_player.Character.getPosition(), m_player.Character.getPosition() + moveOffset, dt * 4.0f));
	}
	//std::cout << "Position of Player: " << m_player.Character.getPosition().x / 48 << " " << m_player.Character.getPosition().y / 48 << "\n";
}

void GameState::lateUpdate(Camera* cam)
{
	cam->lerp(m_player.Character.getPosition() + sf::Vector2f(0.0f, 48.0f), 0.05f);
	cam->setView();
}

void GameState::render(Renderer* renderer)
{
	renderer->addDraw(map.layer1);
	renderer->addDraw(m_player.Character);
	renderer->addDraw(map.layer2);
}
