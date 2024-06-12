#include "BoxRenderer.h"
#include <SFML/Graphics.hpp>

BoxRenderer::BoxRenderer(float _coverage) : coverage(_coverage)
{
}

void BoxRenderer::OnUpdate(float _deltaTime)
{
}

void BoxRenderer::OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition)
{
	sf::CircleShape c = sf::CircleShape(40);
	c.setFillColor(sf::Color(255, 255, 0));
	_window.draw(c);
}
