#pragma once
#include "Component.h"

class BoxRenderer : public Component {
public:
	BoxRenderer(float _coverage);
	float coverage;

	void OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition) override;
};