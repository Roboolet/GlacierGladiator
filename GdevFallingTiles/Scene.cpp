#include <iostream>
#include "Scene.h"
#include <chrono>

Scene::Scene() {
	// this is in seconds
	creationTime = std::chrono::steady_clock::now();

	// awaken the objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
		objects[i].Awaken();
	}
}

void Scene::Update() {
	// periodically create asteroids

	std::chrono::duration<float> elapsed = std::chrono::steady_clock::now() - lastFrameTime;
	lastFrameTime = std::chrono::steady_clock::now();

	// update objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
		objects[i].Update(elapsed.count());
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