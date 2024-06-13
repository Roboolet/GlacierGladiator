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
	double timeSinceStart;
	double deltaTime;

	void CreateGameScene1();

	// objects
	std::vector<GameObject> objects;
	void Update();
	void Awake();
	GameObject* Instantiate(LeaVec2, LeaVec2, std::vector<Component*>);

	// camera and rendering
	LeaVec2 cameraPosition;
	float cameraOrthographicSize;
	void Render(sf::RenderWindow& _window, int, int);

	void CloseScene();

private:
	double lastFrameScreenClearMod;
};