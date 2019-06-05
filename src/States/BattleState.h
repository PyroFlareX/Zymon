#include "Basestate.h"

#include "../Zymon/Battle.h"

class Application;
class Gamestate;

class BattleState :	public Basestate
{
public:
	BattleState(Application& application);

	void input() override;
	void update(sf::RenderWindow* window, float dt) override;
	void lateUpdate(Camera* cam) override;
	void render(Renderer* renderer) override;

	~BattleState() override;
protected:

private:
	Battle battle;
	sf::Text msg;
	sf::Font font;
};
