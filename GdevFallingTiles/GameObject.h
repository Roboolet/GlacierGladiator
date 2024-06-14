#pragma once
#include <SFML/Graphics.hpp>
#include "LeaMath.h"
#include <typeinfo>
#include "Components.h"

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

	void Awaken();
	void Update(double _deltaTime);
	void Draw(sf::RenderWindow& _window, LeaVec2 _screenPosition);

	// i wish i knew how generic types worked in this language
	Component* GetComponent(std::string);

private:
	void InitializeComponents();
};

