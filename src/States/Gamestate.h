#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Basestate.h"
#include "../World/World.h"
#include "../Player.h"
#include "../Application.h"

#include "../Util/Input.h"

class GameState : public Basestate
{
public:
    GameState();

    bool input(Application& app) override;
    void update(sf::RenderWindow* window, float dt) override;
	void lateUpdate(Camera* cam) override;
	void render(Renderer* renderer) override;

	void tryPause();

    ~GameState() override;
protected:


private:
	bool isColliding(sf::Vector2f playerPos);

	Player m_player;
	World map;
	sf::Vector2f moveOffset;

	bool isPaused;
	bool TryPause;
};

#endif // GAMESTATE_H
