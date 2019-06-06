#ifndef BASESTATE_H
#define BASESTATE_H

//#include "../Application.h"
#include "../Renderers/Renderer.h"
#include <SFML/Graphics.hpp>
#include "../Camera.h"

class Application;

class Basestate
{
public:
	Basestate() {};

    virtual bool input(Application &app) = 0;
    virtual void update(sf::RenderWindow* window, float dt) = 0;
	virtual void lateUpdate(Camera* cam) = 0;
	virtual void render(Renderer* renderer) = 0;
	//virtual 

    virtual ~Basestate() = default;
protected:

};


#endif // BASESTATE_H
