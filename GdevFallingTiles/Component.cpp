#include "Component.h"

Component::Component(GameObject* owner) {
	gameObject = owner;
}

Component::~Component() {
	gameObject = nullptr;
}

void Component::OnAwaken()
{
}

void Component::OnUpdate(float _deltaTime)
{
}

void Component::OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition)
{
}
