#include <iostream>
#include "Scene.h"
#include <chrono>
#include "Components.h"

Scene::Scene() {
	// this is in seconds
	creationTime = std::chrono::steady_clock::now();

	// awaken the objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
		objects[i].Awaken();
	}
}

void Scene::CreateGameScene1()
{
	typedef std::vector<Component*> compVec;

	// background
	Instantiate(LeaVec2(0, 0), LeaVec2(192, 108), compVec{ new BoxRenderer(3, 60) });
	// floor
	Instantiate(LeaVec2(0, 50), LeaVec2(192, 20), compVec{ new BoxRenderer(20, 60) });
	// player
	Instantiate(LeaVec2(0, 30), LeaVec2(10, 10), compVec{ new BoxRenderer(20, 60) });

	std::cout << "Objects instantiated: " << objects.size() << std::endl;
}

void Scene::Update() {
	// periodically create asteroids

	auto now = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = now - lastFrameTime;
	lastFrameTime = now;

	// update objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
		objects[i].Update(elapsed.count());
	}
}

GameObject* Scene::Instantiate(LeaVec2 _pos, LeaVec2 _sc, std::vector<Component*> _comps)
{
	GameObject obj = GameObject(_pos, _sc, _comps);
	objects.insert(objects.end(), obj);
	return nullptr;
}

void Scene::Render(sf::RenderWindow& _window, int resolutionX, int resolutionY) {

	// draw objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
		//float screenW = resolutionX / 2;
		//float screenH = resolutionY / 2;
		int screenW = resolutionX / 2;
		int screenH = resolutionY / 2;
		LeaVec2 screenPos = LeaVec2(screenW + objects[i].position.x, screenH + objects[i].position.y);
		objects[i].Draw(_window, screenPos);
	}

}

void Scene::CloseScene() {

	// destroy objects
	objects.clear();
}