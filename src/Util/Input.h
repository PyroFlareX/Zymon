#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

namespace Input
{
	struct Inputs
	{
		bool up;
		bool down;
		bool left;
		bool right;
		bool backwards;
		bool forth;
	};

        Inputs getInput();
};

#endif // INPUT_H
