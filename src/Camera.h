#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera(sf::RenderWindow* p_win);

	sf::Vector2f lerp(sf::Vector2f target, float gradient);
	void setView();
	void setView(sf::View view);

	~Camera();
private:
	sf::RenderWindow* p_window;
	sf::View currentView;
};

