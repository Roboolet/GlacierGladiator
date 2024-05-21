#include <iostream>
#include "GameObject.h"

void GameObject::Awaken() {
	LoadResources();
	OnAwaken();
}

void GameObject::Update(float _deltaTime) {
	OnUpdate(_deltaTime);
}

GameObject::~GameObject() {
	std::cout << "Destroyed GameObject " << name << this << std::endl;
}