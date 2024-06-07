#include <iostream>
#include "Scene.h"

Scene::Scene() {
	// create player, floor, UI

	// awaken the objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
		objects[i].Awaken();
	}
}

void Scene::Update(float _deltaTime) {
	// periodically create asteroids

	// update objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
		objects[i].Update(_deltaTime);
	}
}

void Scene::Render(sf::RenderWindow& _window) {

	// draw objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {

		LeaVec2* screenPos= new LeaVec2();
		objects[i].Draw(_window, screenPos);

		delete(screenPos);
	}

}

void Scene::CloseScene() {

	// destroy objects
	objects.clear();
}