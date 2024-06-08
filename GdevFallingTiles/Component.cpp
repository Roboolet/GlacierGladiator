#include "Component.h"

Component::Component(GameObject* owner) {
	gameObject = owner;
}

Component::~Component() {
	gameObject = nullptr;
}