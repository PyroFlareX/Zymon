#include "BattleState.h"

#include "../Util/Input.h"

BattleState::BattleState()
{
	firstFrame = true;
	//Play Battle Video
	
	//Starting Battle UI		@TODO !!
	font.loadFromFile("res/Fonts/PixelFont.ttf");
	tex.loadFromFile("res/Textures/battlebackground.jpg");

	msg.setFont(font);
	msg.setFillColor(sf::Color::Red);
	msg.setOutlineColor(sf::Color::White);
	msg.setOutlineThickness(4);
	msg.setCharacterSize(18);
	msg.setPosition(sf::Vector2f(575, 475));
	msg.setString("1: Move 1\n2: Move 2\n3: Move 3\n4: Move 4");

	status.setFont(font);
	status.setFillColor(sf::Color::Black);
	status.setCharacterSize(18);
	status.setString("Default");
	status.setOutlineColor(sf::Color::White);
	status.setOutlineThickness(4);

	screen.setTexture(&tex);
	screen.setSize(sf::Vector2f(800, 600));
}

bool BattleState::input(Application &app)
{

	Input::Inputs input = Input::getInput();

	if (input.right)
	{
		std::cout << "Move 4\n";
		status.setString("Used Move 4!");
		// /*@TODO: Create DEMO MOVES*/
		battle.getSelections(Move(Types::NORMAL, 40, "Tackle", 40, 100));
		status.setString("Used Tackle!");
	}
	if (input.left)
	{
		std::cout << "Move 2\n";
		status.setString("Used Move 2!");
		// /*@TODO: Create DEMO MOVES*/
		battle.getSelections(Move(Types::NORMAL, 40, "Tackle", 40, 100)); 
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
		std::cout << "Move 1\n";
		status.setString("Used Move 1!");
		/*@TODO: Create DEMO MOVES*/
		battle.getSelections(Move(Types::NORMAL, 40, "Tackle", 40, 100));
	}
	if (input.backwards)
	{
		std::cout << "Move 3\n";
		status.setString("Used Move 3!");
		/*@TODO: Create DEMO MOVES*/
		battle.getSelections(Move(Types::NORMAL, 40, "Tackle", 40, 100));
	}
	if (battle.checkEnd())
	{
		app.popState();
	}
	return false;
}

void BattleState::update(sf::RenderWindow* window, float dt)
{
	//battle.update();
	if (battle.isSelected())
	{
		if (battle.doTurn())
		{
			status.setString("Utilized the move of Tackle!");
		}
	}
}

void BattleState::lateUpdate(Camera* cam)
{
	if (firstFrame)
	{
		cam->setViewDefault();
		firstFrame = false;
	}
}

void BattleState::render(Renderer* render)
{
	render->addDraw(screen);
	render->addDraw(msg);
	render->addDraw(status);
}

BattleState::~BattleState()
{

}
