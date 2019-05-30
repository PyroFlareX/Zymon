#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Basestate.h"
#include "../Application.h"
#include "../World/World.h"

#include "../Util/Input.h"

class Application;
class Basestate;

class GameState : public Basestate
{
public:
    GameState(Application& application);

    void input(sf::RenderWindow* window) override;
    void update(Renderer* renderer) override;

    ~GameState();
protected:


private:
	sf::Texture tex;
    Input inputHandler;
	sf::Sprite test;
	World map;
};

#endif // GAMESTATE_H
