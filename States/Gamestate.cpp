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
    sf::Vector2f moveOffset(0.0f, 0.0f);
    inputHandler.resetInput();
    inputHandler.getInput(window);
    if(inputHandler.virtualInput.right)
    {
        std::cout << "Going Right!\n";
        moveOffset.x += 5.0f;
    }
    if(inputHandler.virtualInput.left)
    {
        std::cout << "Going Left!\n";
        moveOffset.x -= 5.0f;
    }
    if(inputHandler.virtualInput.up)
    {
        std::cout << "Going Up!\n";
        moveOffset.y -= 5.0f;
    }
    if(inputHandler.virtualInput.down)
    {
        std::cout << "Going Down!\n";
    }
    if(inputHandler.virtualInput.forth)
    {
        std::cout << "Going Forward!\n";
    }
    if(inputHandler.virtualInput.backwards)
    {
        std::cout << "Going Back!\n";
    }

    //playRect.move(moveOffset);
}

void GameState::update(Renderer* renderer)
{
	sf::CircleShape test;
	test.setRadius(50);
	test.setFillColor(sf::Color::Red);
	renderer->addDraw(test);
}
