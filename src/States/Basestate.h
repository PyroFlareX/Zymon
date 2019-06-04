#ifndef BASESTATE_H
#define BASESTATE_H

#include "../Application.h"
#include "../Renderers/Renderer.h"
#include <SFML/Graphics.hpp>
#include "../Camera.h"

class Application;

class Basestate
{
public:
    Basestate(Application& application);

    virtual void input() = 0;
    virtual void update(sf::RenderWindow* window, float dt) = 0;
	virtual void lateUpdate(Camera* cam) = 0;
	virtual void render(Renderer* renderer) = 0;

    virtual ~Basestate() = default;
protected:
    Application* m_application;

};


#endif // BASESTATE_H
