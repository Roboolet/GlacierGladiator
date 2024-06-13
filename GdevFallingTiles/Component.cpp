#include "Component.h"

Component::Component() {
}

Component::~Component() {
	gameObject = nullptr;
}

void Component::OnAwaken()
{
}

void Component::OnUpdate(double _deltaTime)
{
}

void Component::OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition)
{
}
