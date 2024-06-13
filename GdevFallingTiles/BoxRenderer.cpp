#include "BoxRenderer.h"
#include <SFML/Graphics.hpp>
#include "InputSystem.h"
#include <iostream>

BoxRenderer::BoxRenderer(int _pixelsPerFill, float _fillsPerSecond, sf::Color _fillColor, sf::BlendMode _blendMode)
	: pixelsPerFill(_pixelsPerFill), fillsPerSecond(_fillsPerSecond), fillColor(_fillColor), blendMode(_blendMode)
{
	timer = 0;
}

void BoxRenderer::OnUpdate(double _deltaTime)
{
	sizeX = gameObject->scale.x;
	sizeY = gameObject->scale.y;

	timer = timer + _deltaTime;
	if (timer > lastFillTime + (1 / fillsPerSecond)) {
		canFill = true;
		lastFillTime = timer;
	}
}

void BoxRenderer::OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition)
{
	if (canFill) {

		// create image
		sf::Image img;
		img.create(sizeX, sizeY);

		// set pixels
		for (int i = 0; i < pixelsPerFill; i++) {

			LeaVec2 pt = GetRandomPoint();

			img.setPixel(pt.x, pt.y, fillColor);
		}

		// this sucks
		sf::Texture tex;
		tex.create(sizeX, sizeY);
		tex.update(img);
		sf::Sprite sprite;
		sprite.setTexture(tex);

		// set position, screen position 0 should have it centered
		sprite.setPosition(_screenPosition.x - sizeX / 2, _screenPosition.y - sizeY / 2);

		_window.draw(sprite, blendMode);
		canFill = false;
	}
}

LeaVec2 BoxRenderer::GetRandomPoint()
{
	double rU = (((double)rand()-100) / (RAND_MAX));
	double rV = (((double)rand()-100) / (RAND_MAX));
	return GetPoint(rU, rV);
}

LeaVec2 BoxRenderer::GetPoint(double _uLerp, double _vLerp)
{
	float u = (0 * (1.0 - _uLerp)) + (sizeX * _uLerp);
	float v = (0 * (1.0 - _vLerp)) + (sizeY * _vLerp);
	return LeaVec2(u,v);
}
