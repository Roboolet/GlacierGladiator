#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "LeaMath.h"


class Scene {
public:
	Scene();

	// objects
	std::vector<GameObject> objects;
	void Update(float _deltaTime);

	// camera and rendering
	LeaVec2 cameraPosition;
	float cameraOrthographicSize;
	void Render(sf::RenderWindow& _window);

	void CloseScene();
};