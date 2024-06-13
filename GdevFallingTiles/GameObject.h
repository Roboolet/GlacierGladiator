#pragma once
#include <SFML/Graphics.hpp>
#include "LeaMath.h"
#include <typeinfo>

class Component;

class GameObject {
public:
	// constructors
	GameObject();
	GameObject(const GameObject&);
	GameObject(std::vector<Component*> _components);
	GameObject(LeaVec2 _position, LeaVec2 _scale,
		std::vector<Component*> _components);
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
	void Update(double _deltaTime);
	void Draw(sf::RenderWindow& _window, LeaVec2 _screenPosition);

	Component* GetComponent(std::string);

private:
	std::map<std::string, int> componentMap;
	void InitializeComponents();
};