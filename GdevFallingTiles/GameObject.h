#pragma once
#include <SFML/Graphics.hpp>
#include "LeaMath.h"

class GameObject {
public:
	// constructors
	GameObject();
	virtual ~GameObject();

	// fields
	std::string name;
	LeaVec2 position;
	LeaVec2 velocity;

	// methods
	void AddForce(LeaVec2 _vec);
	void Destroy();

	// do not override these, override the
	// protected ones instead
	void Awaken();
	void Update(float _deltaTime);

protected:
	virtual void LoadResources();
	virtual void OnAwaken();
	virtual void OnUpdate(float _deltaTime);
};