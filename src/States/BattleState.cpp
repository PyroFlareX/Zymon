#include "BattleState.h"

#include "../Util/Input.h"

BattleState::BattleState()
{
	//Play Battle Video
	
	//msg. do the settings @TODO
	font.loadFromFile("res/Fonts/PixelFont.ttf");
	msg.setFont(font);
	msg.setFillColor(sf::Color::White);
	msg.setString("1: Move 1\n2: Move 2\n3: Move 3\n4: Move 4");
}

bool BattleState::input(Application &app)
{

	Input::Inputs input = Input::getInput();

	if (input.right)
	{

	}
	if (input.left)
	{

	}
	if (input.up)
	{
		
	}
	if (input.down)
	{
		app.popState();
	}
	if (input.forth)
	{
		
	}
	if (input.backwards)
	{
		
	}
	return false;
}

void BattleState::update(sf::RenderWindow* window, float dt)
{
	battle.update();
}

void BattleState::lateUpdate(Camera* cam)
{
	
}

void BattleState::render(Renderer* render)
{
	render->addDraw(msg);
	if (battle.checkEnd())
	{
		
	}
}

BattleState::~BattleState()
{

}
