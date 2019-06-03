#include "GameState.h"

#include <iostream>

GameState::GameState(Application& app)
: Basestate(app)
{
	sheet.loadFromFile("res/Textures/trainer.png");
	tex.loadFromImage(sheet, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 64)));
	test.setTexture(tex);
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
		tex.loadFromImage(sheet, sf::IntRect(sf::Vector2i(0, 128), sf::Vector2i(48, 64)));
		test.setTexture(tex);
    }
    if(input.left)
    {
        std::cout << "Going Left!\n";
        moveOffset.x -= 48.0f;
		tex.loadFromImage(sheet, sf::IntRect(sf::Vector2i(0, 64), sf::Vector2i(48, 64)));
		test.setTexture(tex);
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
		tex.loadFromImage(sheet, sf::IntRect(sf::Vector2i(0, 192), sf::Vector2i(48, 64)));
		test.setTexture(tex);
    }
    if(input.backwards)
    {
        std::cout << "Going Back!\n";
		moveOffset.y += 48.0f;
		tex.loadFromImage(sheet, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 64)));
		test.setTexture(tex);
    }

	test.move(moveOffset);
	sf::View view(window->getView());
	view.setCenter(test.getPosition() + sf::Vector2f(0.0f , 48.0f));
	window->setView(view);
}

void GameState::update(Renderer* renderer)
{
	std::cout << "Position of Player: " << test.getPosition().x / 48 << " " << test.getPosition().y / 48 << "\n";
	renderer->addDraw(map.tilemap);
	renderer->addDraw(test);
}
