#include "Input.h"
#include <iostream>

void Input::getInput(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        std::cout << "Test\n";
    }
    sf::Event inputEvent;
    while(window->pollEvent(inputEvent))
    {
    if (inputEvent.type == sf::Event::KeyPressed)
        {
        if(inputEvent.key.code == sf::Keyboard::W)
            virtualInput.forth = true;
        if(inputEvent.key.code == sf::Keyboard::S)
            virtualInput.backwards = true;
        if(inputEvent.key.code == sf::Keyboard::Space)
            virtualInput.up = true;
        if(inputEvent.key.code == sf::Keyboard::A)
            virtualInput.left = true;
        if(inputEvent.key.code == sf::Keyboard::D)
            virtualInput.right = true;
        if(inputEvent.key.code == sf::Keyboard::LShift)
            virtualInput.down = true;
        if(inputEvent.key.code == sf::Keyboard::Escape)
            window->close();
        }
    if(inputEvent.type == sf::Event::Closed)
        {
            window->close();
        }
    }
    return;
}

void Input::resetInput()
{
    virtualInput.up = false;
    virtualInput.down = false;
    virtualInput.left = false;
    virtualInput.right = false;
    virtualInput.backwards = false;
    virtualInput.forth = false;
    return;
}
