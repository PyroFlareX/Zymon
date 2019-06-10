#include "GameState.h"

#include <iostream>
#include "../Util/math.h"
#include "BattleState.h"

GameState::GameState()
{
	TryPause = false;
}

GameState::~GameState()
{

}

bool GameState::input(Application &app)
{
	moveOffset = sf::Vector2f(0.f, 0.f);

	Input::Inputs input;
	if (!isPaused)
	{
		input = Input::getInput();

		if (input.right)
		{
			std::cout << "Going Right!\n";
			moveOffset.x += 48.0f;
			m_player.updateDirection(0);
		}
		else
			if (input.left)
			{
				std::cout << "Going Left!\n";
				moveOffset.x -= 48.0f;
				m_player.updateDirection(1);
			}
			else
				if (input.up)
				{
					std::cout << "Going Up!\n";
					std::cout << "Dev Short Cut: Battling\n";
					tryPause();
					app.pushState(std::make_unique<BattleState>());
					
				}
				else
					if (input.down)
					{
						std::cout << "Going Down!\n";
					}
					else
						if (input.forth)
						{
							std::cout << "Going Forward!\n";
							moveOffset.y -= 48.0f;
							m_player.updateDirection(2);
						}
						else
							if (input.backwards)
							{
								std::cout << "Going Back!\n";
								moveOffset.y += 48.0f;
								m_player.updateDirection(3);
							}
	}
	return false;
}

void GameState::update(sf::RenderWindow* window, float dt)
{
	if (window->hasFocus() && !TryPause)
	{
		isPaused = false;
	}
	else
	{
		isPaused = true;
		TryPause = false;
	}
	if (!isPaused)
	{
		sf::Vector2f pos = m_player.Character.getPosition();
		m_player.Character.setPosition(lerp(m_player.Character.getPosition(), m_player.Character.getPosition() + moveOffset, dt * 4.0f));
		/// Collision Detection Here

		if (isColliding(pos))
		{
			std::cout << "COLLISION!\n";
		}
	}
}

void GameState::lateUpdate(Camera* cam)
{
	cam->lerp(m_player.Character.getPosition() + sf::Vector2f(0.0f, 48.0f), 0.1f);
	cam->setView();
}

void GameState::render(Renderer* renderer)
{
	renderer->addDraw(map.layer1);
	renderer->addDraw(map.layer2);
	renderer->addDraw(m_player.Character);
}

void GameState::tryPause()
{
	TryPause = true;
}

bool GameState::isColliding(sf::Vector2f playerPos)
{
	/// Collision Detection Here
	//Left
	if (m_player.Character.getGlobalBounds().intersects(sf::FloatRect(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(-10.0f, 1776.0f))))
	{
		m_player.Character.setPosition(playerPos);
		return true;
	}
	//Bottom
	if (m_player.Character.getGlobalBounds().intersects(sf::FloatRect(sf::Vector2f(0.0f, 1776.0f), sf::Vector2f(2400.0f, 1786.0f))))
	{
		m_player.Character.setPosition(playerPos);
		return true;
	}
	//Top
	if (m_player.Character.getGlobalBounds().intersects(sf::FloatRect(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2400.0f, -10.0f))))
	{
		m_player.Character.setPosition(playerPos);
		return true;
	}
	//Right
	if (m_player.Character.getGlobalBounds().intersects(sf::FloatRect(sf::Vector2f(2400.0f, 0.0f), sf::Vector2f(2450.0f, 1776.0f))))
	{
		m_player.Character.setPosition(playerPos);
		return true;
	}
	return false;
}
