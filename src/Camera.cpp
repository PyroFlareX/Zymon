#include "Camera.h"

Camera::Camera(sf::RenderWindow* p_win)
{
	p_window = p_win;
}

sf::Vector2f Camera::lerp(sf::Vector2f target, float gradient)
{
	currentView = p_window->getView();

	sf::Vector2f offset = ((target - currentView.getCenter()) * gradient);
	currentView.move(offset);

	return offset;
}

void Camera::setView()
{
	p_window->setView(currentView);
}

void Camera::setView(sf::View view)
{
	p_window->setView(view);
}

Camera::~Camera()
{

}
