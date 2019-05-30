#include "Input.h"
#include <iostream>

Input::Inputs Input::getInput()
{
	Input::Inputs input = { false, false, false, false, false, false };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		input.forth = true;
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			input.backwards = true;
		}
		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				input.left = true;
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					input.right = true;
				}
			}
		}
	}
	return input;
}
