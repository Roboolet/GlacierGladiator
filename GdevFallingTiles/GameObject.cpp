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

void GameObject::Update(double _deltaTime) {
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnUpdate(_deltaTime);
	}
}

void GameObject::Draw(sf::RenderWindow& _window, LeaVec2 _screenPosition) {
	for (int i = 0; i < components.size(); i++) {
		components[i]->OnDraw(_window, _screenPosition);
	}
}

Component* GameObject::GetComponent(std::string _typeName)
{
	Component* comp = nullptr;
	for (int i = 0; i < components.size(); i++) {
		if (typeid(*components[i]).name() == _typeName) {
			comp = components[i];
		}
	}

	return comp;
}

void GameObject::InitializeComponents()
{
	for (int i = 0; i < components.size(); i++) {
		components[i]->gameObject = this;
		std::cout << "Initialized component: " << typeid(*components[i]).name() << std::endl;		
	}	
}

GameObject::GameObject()
{
}

GameObject::GameObject(const GameObject& old)
{
	position = old.position;
	scale = old.scale;
	components = old.components;
	InitializeComponents();

	std::cout << "Scene: Copied GameObject " << &old << " into new object " << this << std::endl;
}

GameObject::GameObject(std::vector<Component*> _components) : components(_components)
{
	scale = LeaVec2(1,1);
	InitializeComponents();
	std::cout << "Scene: Created GameObject " << this << " with " <<
		components.size() << " components" << std::endl;
}

GameObject::GameObject(LeaVec2 _position, LeaVec2 _scale, std::vector<Component*> _components)
	: components(_components), position(_position), scale(_scale)
{
	InitializeComponents();
	std::cout << "Scene: Created GameObject " << this << " with " << 
		components.size() << " components" << std::endl;
}

GameObject::~GameObject() {
	components.clear();
	std::cout << "Scene: Destroyed GameObject " << name << this << std::endl;
}