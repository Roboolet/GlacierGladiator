#pragma once
#include <SFML/Graphics.hpp>
#include "LeaMath.h"
#include "Components.h"

class Scene;

class GameObject {
public:
	// constructors
	GameObject();
	GameObject(const GameObject&);
	GameObject(std::vector<Component*> _components);
	GameObject(LeaVec2 _position, LeaVec2 _scale,
		std::vector<Component*> _components);
	virtual ~GameObject();

	bool enabled = true;
	std::string name;
	LeaVec2 position, scale;
	//float rotation;
	std::vector<Component*> components;
	Scene* scene;

	void Awaken();
	void Update(double _deltaTime);
	void Draw(sf::RenderWindow& _window, LeaVec2 _screenPosition);
	//LeaMatrix3x2 GetPRS();

	// i wish i knew how generic types worked in this language
	Component* GetComponent(std::string);

private:
	void InitializeComponents();
};

