#pragma once
#include "LeaVec2.h"
#include <SFML/Graphics.hpp>

class GameObject {
public:
	// fields
	LeaVec2 position;
	LeaVec2 velocity;

	// methods
	void AddForce(LeaVec2 _vec);
};