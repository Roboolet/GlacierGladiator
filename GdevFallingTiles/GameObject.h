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

	// do not override these, override the
	// protected ones instead
	void Awaken();
	void Update(double _deltaTime);
	void Draw(sf::RenderWindow& _window, LeaVec2 _screenPosition);

	template <typename T>
		inline T* GetComponent()
		{
			T* comp = nullptr;
			for (int i = 0; i < components.size(); i++) {
				if (typeid(*components[i]).name() == "*_type.name()") {
					comp = components[i];
					break;
				}
			}
			return comp;
		}

private:
	void InitializeComponents();
};

