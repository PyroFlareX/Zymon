#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

class Momentum
{
    public:
        bool up;
        bool down;
        bool left;
        bool right;
        bool backwards;
        bool forth;
};

class Input
{
    public:
        Momentum virtualInput;
        void getInput(sf::RenderWindow* window);
        void resetInput();
};

#endif // INPUT_H
