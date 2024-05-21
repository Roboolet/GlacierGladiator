#include <iostream>
#include "GameObject.h"

void GameObject::Awaken() {
	name = "unnamed";
	LoadResources();
	OnAwaken();
}

void GameObject::Update(float _deltaTime) {
	OnUpdate(_deltaTime);
}

GameObject::~GameObject() {
	std::cout << "Destroyed GameObject " << name << this << std::endl;
}