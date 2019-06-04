#ifndef BASESTATE_H
#define BASESTATE_H

#include "../Application.h"
#include "../Renderers/Renderer.h"
#include <SFML/Graphics.hpp>

class Application;

class Basestate
{
public:
    Basestate(Application& application);

    virtual void input(sf::RenderWindow* window) = 0;
    virtual void update(Renderer* renderer, sf::RenderWindow* window, float dt) = 0;

    virtual ~Basestate() = default;
protected:
    Application* m_application;

};


#endif // BASESTATE_H
