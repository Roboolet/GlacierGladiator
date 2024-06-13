#pragma once
#include "Component.h"

class BoxRenderer : public Component {
public:
	BoxRenderer(int, float);
	int pixelsPerFill;
	float fillsPerSecond;

	virtual void OnUpdate(double _deltaTime) override;
	virtual void OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition) override;


private:
	int sizeX, sizeY;
	double lastFillTime;
	double timer;
	bool canFill;
	LeaVec2 GetRandomPoint();
	LeaVec2 GetPoint(double _uLerp, double _vLerp);

};