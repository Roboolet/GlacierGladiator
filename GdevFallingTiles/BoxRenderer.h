#pragma once
#include "Component.h"

class BoxRenderer : public Component {
public:
	BoxRenderer(float _coverage);
	float coverage;

	virtual void OnUpdate(float _deltaTime) override;
	virtual void OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition) override;
};