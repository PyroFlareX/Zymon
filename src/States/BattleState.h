#include "Basestate.h"

#include "../Zymon/Battle.h"
#include "Basestate.h"


class BattleState :	public Basestate
{
public:
	BattleState();

	bool input(Application &app) override;
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
