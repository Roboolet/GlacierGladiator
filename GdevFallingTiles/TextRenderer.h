#pragma once
#include "Component.h"
#include "GameObject.h"

class TextRenderer : public Component {
public:
	TextRenderer(std::string, int);
	virtual void OnAwaken() override;
	virtual void OnDraw(sf::RenderWindow&, LeaVec2) override;

	std::string text;
	int fontSize;

private:
	sf::Font font;
};