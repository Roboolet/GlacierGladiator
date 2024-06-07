#include <iostream>
#include "GameObject.h"

void GameObject::Awaken() {
	name = "unnamed";
	OnAwaken();
}

LeaMatrix3x2 GameObject::GetPRS() {
	LeaMatrix3x2 mat = LeaMatrix3x2();
	return mat;
}

void GameObject::Update(float _deltaTime) {
	OnUpdate(_deltaTime);
}

void GameObject::Draw(sf::RenderWindow& _window, LeaVec2 _screenPosition) {
	
}


void GameObject::OnAwaken() {

}
void GameObject::OnUpdate(float _deltaTime) {

}

GameObject::~GameObject() {
	std::cout << "Destroyed GameObject " << name << this << std::endl;
}