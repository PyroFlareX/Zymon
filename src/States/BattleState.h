#include "Basestate.h"


class BattleState :	public Basestate
{
public:
	BattleState(Application& application);

	void input(sf::RenderWindow* window) override;
	void update(Renderer* renderer, sf::RenderWindow* window, float dt) override;

	~BattleState();
protected:

private:

};
