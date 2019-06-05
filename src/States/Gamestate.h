#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Basestate.h"
#include "../Application.h"
#include "../World/World.h"
#include "../Player.h"

#include "../Util/Input.h"

class Basestate;
class BattleState;

class GameState : public Basestate
{
public:
    GameState(Application& application);

    void input() override;
    void update(sf::RenderWindow* window, float dt) override;
	void lateUpdate(Camera* cam) override;
	void render(Renderer* renderer) override;

    ~GameState() override;
protected:


private:
	Player m_player;
	World map;
	sf::Vector2f moveOffset;
	float wait;
	sf::View view;
};

#endif // GAMESTATE_H
