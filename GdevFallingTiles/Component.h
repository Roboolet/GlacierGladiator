#pragma once
#include <SFML/Graphics.hpp>
#include "LeaMath.h"
#include "GameObject.h"

class Component {
public:
	Component();
	virtual ~Component();

	// merely a reference to the gameobject that owns this
	GameObject* gameObject;

	virtual void OnAwaken();
	virtual void OnUpdate(float _deltaTime);

	// use interfaces for this?
	virtual void OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition);

};