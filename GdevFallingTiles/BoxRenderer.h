#pragma once
#include "Component.h"
#include "GameObject.h"

class BoxRenderer : public Component {
public:
	BoxRenderer(int, float, sf::Color, sf::BlendMode);
	int pixelsPerFill;
	float fillsPerSecond;
	sf::Color fillColor;
	sf::BlendMode blendMode;

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