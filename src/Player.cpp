#include "Player.h"


Player::Player()
{
	sheet.loadFromFile("res/Textures/trainer.png");
	tex.loadFromImage(sheet, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 64)));
	Character.setTexture(tex);
	Character.move(sf::Vector2f(4.0f, 0.0f));
}

sf::FloatRect Player::getBounds()
{
	return Character.getGlobalBounds();
}

void Player::updateDirection(int direction)
{
	if (facingDir == direction)
	{
		tileSteps = tileSteps + 64;
		if (tileSteps >= 192)
		{
			tileSteps = 0;
		}
	}
	else
	{
		facingDir = direction;
		tileSteps = 0;
	}

	if (facingDir == 0)
	{
		tex.loadFromImage(sheet, sf::IntRect(sf::Vector2i(tileSteps, 128), sf::Vector2i(48, 64)));
		Character.setTexture(tex);
	}
	if (facingDir == 1)
	{
		tex.loadFromImage(sheet, sf::IntRect(sf::Vector2i(tileSteps, 64), sf::Vector2i(48, 64)));
		Character.setTexture(tex);
	}
	if (facingDir == 2)
	{
		tex.loadFromImage(sheet, sf::IntRect(sf::Vector2i(tileSteps, 192), sf::Vector2i(48, 64)));
		Character.setTexture(tex);
	}
	if (facingDir == 3)
	{
		tex.loadFromImage(sheet, sf::IntRect(sf::Vector2i(tileSteps, 0), sf::Vector2i(48, 64)));
		Character.setTexture(tex);
	}
}

Player::~Player()
{
	tex.~Texture();
	sheet.~Image();
}
