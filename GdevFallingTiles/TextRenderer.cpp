#include "TextRenderer.h"
#include <iostream>

TextRenderer::TextRenderer(std::string _text, int _size) : text(_text), fontSize(_size)
{
}

void TextRenderer::OnAwaken()
{
	// idk how to include my own fonts in builds so i give up and just use arial
	//std::string path = "C:/Windows/Fonts/Retro Gaming Regular.ttf";
	std::string path = "C:\\Windows\\Fonts\\Arial.ttf";
	if (!font.loadFromFile(path))
	{
		std::cout << "Couldn't load font " << path << std::endl;
		
	}
	else {
		std::cout << "Successfully loaded font " << path << std::endl;
	}
}

void TextRenderer::OnDraw(sf::RenderWindow& _window, LeaVec2 _screenPosition)
{
	sf::Text t;
	t.setFont(font);
	t.setString(text);
	t.setCharacterSize(fontSize);
	t.setFillColor(sf::Color::White);
	t.setPosition(_screenPosition.x, _screenPosition.y);
	_window.draw(t);

}
