#include "GameState.h"

#include <iostream>

GameState::GameState(Application& app)
: Basestate(app)
{
	tex.loadFromFile("res/Textures/trainer.png", sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 64)));
	test.setTexture(tex);
}

GameState::~GameState()
{

}

void GameState::input(sf::RenderWindow* window)
{
    sf::Vector2f moveOffset(0.0f, 0.0f);
    inputHandler.resetInput();
    inputHandler.getInput(window);
    if(inputHandler.virtualInput.right)
    {
        std::cout << "Going Right!\n";
        moveOffset.x += 32.0f;
    }
    if(inputHandler.virtualInput.left)
    {
        std::cout << "Going Left!\n";
        moveOffset.x -= 32.0f;
    }
    if(inputHandler.virtualInput.up)
    {
        std::cout << "Going Up!\n";
    }
    if(inputHandler.virtualInput.down)
    {
        std::cout << "Going Down!\n";
    }
    if(inputHandler.virtualInput.forth)
    {
        std::cout << "Going Forward!\n";
		moveOffset.y -= 32.0f;
    }
    if(inputHandler.virtualInput.backwards)
    {
        std::cout << "Going Back!\n";
		moveOffset.y += 32.0f;
    }

	test.move(moveOffset);
}

void GameState::update(Renderer* renderer)
{
	renderer->addDraw(map.tilemap);
	renderer->addDraw(test);
}
