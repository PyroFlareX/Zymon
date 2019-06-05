#include "BattleState.h"

#include "../Util/Input.h"

BattleState::BattleState(Application& app)
	: Basestate(app)
{
	//Play Battle Video
	
	//msg. do the settings @TODO
	font.loadFromFile("res/Fonts/PixelFont.ttf");
	msg.setFont(font);
	msg.setFillColor(sf::Color::White);
	msg.setString("1: Move 1\n2: Move 2\n3: Move 3\n4: Move 4");
}

void BattleState::input()
{
	battle.waitForSelection();

	Input::Inputs input = Input::getInput();

	if (input.right)
	{
		//m_application->pushState(std::unique_ptr<BattleState>(dynamic_cast<BattleState*>(m_application)));
	}
	if (input.left)
	{

	}
	if (input.up)
	{
		
	}
	if (input.down)
	{
		
	}
	if (input.forth)
	{
		
	}
	if (input.backwards)
	{
		
	}
}

void BattleState::update(sf::RenderWindow* window, float dt)
{
	if (battle.isSelected())
	{
		battle.doTurn();
		battle.nextTurn();
	}
}

void BattleState::lateUpdate(Camera* cam)
{
	//cam->setView(sf::View());
}

void BattleState::render(Renderer* render)
{
	render->addDraw(msg);
	if (battle.checkEnd())
	{
		m_application->popState();
	}
}

BattleState::~BattleState()
{
	//m_application->popState();
}
