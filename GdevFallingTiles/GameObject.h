#pragma once
#include <SFML/Graphics.hpp>
#include "LeaMath.h"

class Component;

class GameObject {
public:
	// constructors
	GameObject();
	GameObject(std::vector<Component*> _components);
	virtual ~GameObject();

	// fields
	std::string name;
	LeaVec2 position, scale;
	//float rotation;
	std::vector<Component*> components;

	// generally useful methods
	//LeaMatrix3x2 GetPRS();

	// do not override these, override the
	// protected ones instead
	void Awaken();
	void Update(float _deltaTime);
	void Draw(sf::RenderWindow& _window, LeaVec2 _screenPosition);
};