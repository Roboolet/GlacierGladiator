#include <iostream>
#include "Scene.h"

Scene::Scene() {
	// create player, floor, UI
	creationTime = std::clock();

	// awaken the objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
		objects[i].Awaken();
	}
}

void Scene::Update() {
	// periodically create asteroids

	float dt = std::clock() - lastFrameTime;
	lastFrameTime = std::clock();

	// update objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
		objects[i].Update(dt);
	}
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