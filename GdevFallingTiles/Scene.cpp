#include <iostream>
#include "Components.h"
#include "Scene.h"
#include <chrono>

Scene::Scene() {
}

void Scene::CreateGameScene1()
{
	// this too should ideally be done in some format like json or xml, but it'll do the job
	typedef std::vector<Component*> compVec;

	// background
	Instantiate(LeaVec2(0, 0), LeaVec2(192, 108), compVec{ 
		new BoxRenderer(150, 60, sf::Color(73,35,29,255), sf::BlendAdd) });
	// floor
	Instantiate(LeaVec2(-100, 40), LeaVec2(200, 15), compVec{ 
		new BoxRenderer(800, 60, sf::Color(36,150,197,125), sf::BlendAdd),
		new Rigidbody(),
		new BoxCollider() });
	// player
	Instantiate(LeaVec2(0, -20), LeaVec2(10, 10), compVec{
		new BoxRenderer(100, 60, sf::Color(110,150,170,255), sf::BlendAdd),
		new Player(),
		new Rigidbody(),
		new BoxCollider() });

	std::cout << "Objects instantiated: " << objects.size() << std::endl;
}


void Scene::PhysicsUpdate()
{
	std::vector<Rigidbody*> rbs;

	// gather all the rigidbodies
	for (int i = 0; i < objects.size(); i++) {
		// this convolluted getcomponent is the only way i could 
		// make it work with my current knowledge
		Rigidbody* rb = dynamic_cast<Rigidbody*>(objects[i].GetComponent(typeid(Rigidbody).name()));

		if (rb != nullptr) {
			rbs.insert(rbs.end(), rb);
		}
	}

	// add restorative forces and adjust positions
	// every rigidbody against every other rigidbody
	for (int i = 0; i < rbs.size(); i++) {
		Rigidbody* rbA = rbs[i];

		for (int i = 0; i < rbs.size(); i++) {
			Rigidbody* rbB = rbs[i];
			if (rbA != rbB) {

				// what a mess
				BoxCollider* boxA = dynamic_cast<BoxCollider*>
					(rbA->gameObject->GetComponent(typeid(BoxCollider).name()));
				BoxCollider* boxB = dynamic_cast<BoxCollider*>
					(rbB->gameObject->GetComponent(typeid(BoxCollider).name()));

				// check for interesctions
				// using the logic from https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection
				if (boxA->topL.x < boxB->topL.x + boxB->width &&
					boxA->topL.x + boxA->width > boxB->topL.x &&
					boxA->topL.y < boxB->topL.y + boxB->height &&
					boxA->topL.y + boxA->height > boxB->topL.y) {
					// collision detected
					std::cout <<
						" AtopL: " << boxA->topL.x << ", " << boxA->topL.y <<
						"; BtopL: " << boxB->topL.x << ", " << boxB->topL.y << std::endl <<
						" AbotR: " << boxA->botR.x << ", " << boxA->botR.y <<
						"; BbotR: " << boxB->botR.x << ", " << boxB->botR.y <<
						std::endl;
				}
				else {
					// no collision

				}
			}
		}
	}
}

void Scene::Update() {
	// periodically create asteroids

	// calculate deltatime and time since start
	auto now = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = now - lastFrameTime;
	lastFrameTime = now;
	deltaTime =  std::fmin(elapsed.count(), 1);

	timeSinceStart = (now - creationTime).count();

	// update objects
	for (int i = 0; i < objects.size(); i++) {
		objects[i].Update(deltaTime);
	}
}

void Scene::Awake()
{
	// this is in seconds
	creationTime = std::chrono::steady_clock::now();

	// awaken the objects
	for (int i = 0; i < objects.size(); i++) {
		objects[i].Awaken();
	}
}

GameObject* Scene::Instantiate(LeaVec2 _pos, LeaVec2 _sc, std::vector<Component*> _comps)
{
	GameObject obj = GameObject(_pos, _sc, _comps);
	objects.insert(objects.end(), obj);
	return nullptr;
}

void Scene::Render(sf::RenderWindow& _window, int resolutionX, int resolutionY) {

	// clears the screen every n nanoseconds (i think?)
	// i wanted to make this game without window clears but sadly this
	// rendering library is really not made for that
	double m = std::fmod(timeSinceStart, 50000000);
	if (m < lastFrameScreenClearMod) {
		_window.clear();
	}

	lastFrameScreenClearMod = m;
		

	// draw objects
	auto size = objects.size();
	for (int i = 0; i < size; i++) {
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