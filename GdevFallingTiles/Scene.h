#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "LeaMath.h"


class Scene {
public:
	Scene();
	float creationTime;

	// objects
	std::vector<GameObject> objects;
	void Update();

	// camera and rendering
	LeaVec2 cameraPosition;
	float cameraOrthographicSize;
	void Render(sf::RenderWindow& _window);

	void CloseScene();
};