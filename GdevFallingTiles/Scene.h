#pragma once
#include <SFML/Graphics.hpp>
#include "LeaMath.h"
#include "GameObject.h"
#include <chrono>

enum Gamestate{Playing, Won, Lost};

class Scene {
public:
	Scene();
	std::chrono::steady_clock::time_point creationTime;
	std::chrono::steady_clock::time_point lastFrameTime;
	double timeSinceStart;
	double deltaTime;

	void CreateGameScene1();
	Gamestate gamestate;

	// objects
	std::vector<GameObject*> objects;
	void PhysicsUpdate();
	void Update();
	void Awake();
	GameObject* Instantiate(std::string, LeaVec2, LeaVec2, std::vector<Component*>);
	GameObject* Find(std::string _name);

	// camera and rendering
	LeaVec2 cameraPosition;
	float cameraOrthographicSize;
	void Render(sf::RenderWindow& _window, int, int);

	void CloseScene();

private:
	double lastFrameScreenClearMod;
};
