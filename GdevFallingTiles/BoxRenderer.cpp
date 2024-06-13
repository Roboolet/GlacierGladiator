#include "BoxRenderer.h"
#include <SFML/Graphics.hpp>
#include "InputSystem.h"

BoxRenderer::BoxRenderer(float _coverage) : coverage(_coverage)
{
}

void BoxRenderer::OnUpdate(float _deltaTime)
{
}

void BoxRenderer::OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition)
{
	sizeX = gameObject->scale.x;
	sizeY = gameObject->scale.y;

	// create image
	sf::Image img;
	img.create(sizeX, sizeY);

	// set pixels
	int pixlAmt = sizeX * sizeY * coverage;
	for (int i = 0; i < pixlAmt; i++) {
		
		LeaVec2 pt = GetRandomPoint();

		img.setPixel(pt.x, pt.y, sf::Color(0,255,255,60));
	}	

	// this sucks
	sf::Texture tex;
	tex.create(sizeX, sizeY);
	tex.update(img);
	sf::Sprite sprite;
	sprite.setTexture(tex);

	// set position, screen position 0 should have it centered
	sprite.setPosition(_screenPosition.x - sizeX/2, _screenPosition.y - sizeY/2);

	_window.draw(sprite, sf::BlendAdd);
}

LeaVec2 BoxRenderer::GetRandomPoint()
{
	double rU = (((double)rand()-100) / (RAND_MAX));
	double rV = (((double)rand()-100) / (RAND_MAX));
	return GetPoint(rU, rV);
}

LeaVec2 BoxRenderer::GetPoint(double _uLerp, double _vLerp)
{
	int u = (0 * (1.0 - _uLerp)) + (sizeX * _uLerp);
	int v = (0 * (1.0 - _vLerp)) + (sizeY * _vLerp);
	return LeaVec2(u,v);
}
