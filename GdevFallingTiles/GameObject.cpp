#include <iostream>
#include "GameObject.h"
#include "Component.h"

void GameObject::Awaken() {
	name = "unnamed";
}

/*LeaMatrix3x2 GameObject::GetPRS() {
	LeaMatrix3x2 mat = LeaMatrix3x2();
	return mat;
}*/

void GameObject::Update(float _deltaTime) {
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnUpdate(_deltaTime);
	}
}

void GameObject::Draw(sf::RenderWindow& _window, LeaVec2 _screenPosition) {
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnDraw(_window, _screenPosition);
	}
}

GameObject::GameObject()
{
	scale = LeaVec2(1, 1);
}

GameObject::GameObject(std::vector<Component*> _components) : components(_components)
{
	scale = LeaVec2(10, 10);
	for (int i = 0; i < components.size(); i++) {
		components[i]->gameObject = this;
	}
}

GameObject::~GameObject() {
	components.clear();
	std::cout << "Destroyed GameObject " << name << this << std::endl;
}