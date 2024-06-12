#pragma once
#include "Component.h"

class BoxRenderer : public Component {
public:
	BoxRenderer(float _coverage);
	float coverage;
	int sizeX = 192, sizeY = 108;

	virtual void OnUpdate(float _deltaTime) override;
	virtual void OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition) override;

private:
	LeaVec2 GetRandomPoint();
	LeaVec2 GetPoint(double _uLerp, double _vLerp);

};