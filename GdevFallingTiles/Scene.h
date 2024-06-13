#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "LeaMath.h"
#include <chrono>


class Scene {
public:
	Scene();
	std::chrono::steady_clock::time_point creationTime;
	std::chrono::steady_clock::time_point lastFrameTime;

	// objects
	std::vector<GameObject> objects;
	void Update();

	// camera and rendering
	LeaVec2 cameraPosition;
	float cameraOrthographicSize;
	void Render(sf::RenderWindow& _window, int, int);

	void CloseScene();
};