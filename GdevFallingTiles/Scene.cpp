#include <iostream>
#include "Components.h"
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

void Scene::CreateGameScene1()
{
	typedef std::vector<Component*> compVec;

	// background
	Instantiate(LeaVec2(0, 0), LeaVec2(192, 108), compVec{ 
		new BoxRenderer(150, 60, sf::Color(73,35,29,255), sf::BlendAdd) });
	// floor
	Instantiate(LeaVec2(0, 50), LeaVec2(192, 20), compVec{ 
		new BoxRenderer(800, 60, sf::Color(16,150,197,75), sf::BlendAdd) });
	// player
	Instantiate(LeaVec2(0, 30), LeaVec2(10, 10), compVec{
		new BoxRenderer(100, 60, sf::Color(110,150,170,255), sf::BlendAdd),
		new Player(),
		new Rigidbody() });

	std::cout << "Objects instantiated: " << objects.size() << std::endl;
}

void Scene::Update() {
	// periodically create asteroids

	auto now = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = now - lastFrameTime;
	lastFrameTime = now;
	deltaTime = elapsed.count();

	timeSinceStart = (now - creationTime).count();

	// update objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
		objects[i].Update(deltaTime);
	}
}

GameObject* Scene::Instantiate(LeaVec2 _pos, LeaVec2 _sc, std::vector<Component*> _comps)
{
	GameObject obj = GameObject(_pos, _sc, _comps);
	objects.insert(objects.end(), obj);
	return nullptr;
}

void Scene::Render(sf::RenderWindow& _window, int resolutionX, int resolutionY) {

	// clears the screen every n nanoseconds
	// i wanted to make this game without clears but sadly this
	// framework is really not made for this
	double m = std::fmod(timeSinceStart, 50000000);
	if (m < lastFrameScreenClearMod) {
		_window.clear();
	}

	lastFrameScreenClearMod = m;
		

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