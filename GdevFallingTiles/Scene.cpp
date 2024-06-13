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
		GameObject go = objects[i];

		float screenW = resolutionX / 2;
		float screenH = resolutionY / 2;
		LeaVec2 screenPos = LeaVec2(screenW + go.position.x, screenH + go.position.y);
		go.Draw(_window, screenPos);
	}

}

void Scene::CloseScene() {

	// destroy objects
	objects.clear();
}