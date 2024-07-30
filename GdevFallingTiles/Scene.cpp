#include <iostream>
#include "Components.h"
#include "GameObject.h"
#include "Scene.h"

#include <chrono>

Scene::Scene() {
}

void Scene::CreateGameScene1()
{
	// this too should ideally be done in some format like json or xml, but it'll do the job
	objects.clear();

	// background
	Instantiate("bg", LeaVec2(-96, -54), LeaVec2(192, 108), compVec{
		new BoxRenderer(150, 60, sf::Color(73,35,29,255), sf::BlendAdd) });

	// floor
	Instantiate("floor", LeaVec2(-100, 40), LeaVec2(200, 15), compVec{
		new BoxRenderer(800, 60, sf::Color(36,150,197,125), sf::BlendAdd),
		new Rigidbody(BodyType::Static),
		new BoxCollider() });
	Instantiate("floorTop", LeaVec2(-100, 40), LeaVec2(200, 2), compVec{
		new BoxRenderer(400, 60, sf::Color(36,150,197,125), sf::BlendAdd) });

	// player
	Instantiate("player", LeaVec2(0, -20), LeaVec2(10, 10), compVec{
		new BoxRenderer(100, 60, sf::Color(110,150,170,255), sf::BlendAdd),
		new Player(),
		new Rigidbody(BodyType::Dynamic),
		new BoxCollider() });

	// meteor spawner
	Instantiate("meteorSpawner", LeaVec2(0, -75), LeaVec2(90, 2), compVec{
		new MeteorSpawner(30, 1400000000)});

	// score display
	Instantiate("score", LeaVec2(-92, 42), LeaVec2(15, 15), compVec{
		new TextRenderer("Score: 0", 8)});

	std::cout << "Objects instantiated: " << objects.size() << std::endl;
}


void Scene::PhysicsUpdate()
{
	std::vector<Rigidbody*> rbs;

	// gather all the rigidbodies
	for (int i = 0; i < objects.size(); i++) {
		// this convolluted getcomponent is the only way i could 
		// make it work with my current knowledge
		if (objects[i]->enabled) {
			Rigidbody* rb = dynamic_cast<Rigidbody*>(objects[i]->GetComponent(typeid(Rigidbody).name()));

			if (rb != nullptr) {
				rbs.insert(rbs.end(), rb);
				rb->collidedLastFrame = false;
			}
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

					rbA->collidedLastFrame = true;
					rbB->collidedLastFrame = true;

					// restorative force
					// just assume it came from above, since this only matters for
					// the player and floor anyways
					if (rbA->bodyType == BodyType::Dynamic) {
						rbA->velocity = LeaVec2(rbA->velocity.x, std::min((float)-0.01f, rbA->velocity.y));

					}
					if (rbB->bodyType == BodyType::Dynamic) {
						rbB->velocity = LeaVec2(rbB->velocity.x, std::min((float)-0.01f, rbA->velocity.y));
					}
				}
				else {
					// no collision

				}
			}
		}
	}
}

void Scene::Update() {

	srand(timeSinceStart + deltaTime);

	// calculate deltatime and time since start
	auto now = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = now - lastFrameTime;
	lastFrameTime = now;
	deltaTime =  std::fmin(elapsed.count(), 1);

	// i think this is in nanoseconds, and i cant seem to fix it
	timeSinceStart = (now - creationTime).count();

	// update objects
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Update(deltaTime);
	}
}

void Scene::Awake()
{
	// this is in seconds
	creationTime = std::chrono::steady_clock::now();
}

GameObject* Scene::Instantiate(std::string _n, LeaVec2 _pos,
	LeaVec2 _sc, std::vector<Component*> _comps)
{
	GameObject* obj = new GameObject(_pos, _sc, _comps);
	obj->scene = this;
	obj->name = _n;
	objects.insert(objects.end(), obj);

	obj->Awaken();
	return obj;
}

GameObject* Scene::Find(std::string _name)
{
	for (int i = 0; i < objects.size(); i++) {
		GameObject* obj = objects[i];
		if (objects[i]->name == _name) {
			return objects[i];
		}
	}
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
		LeaVec2 screenPos = LeaVec2(screenW + objects[i]->position.x, screenH + objects[i]->position.y);
		objects[i]->Draw(_window, screenPos);
	}

}

void Scene::CloseScene() {

	// destroy objects
	for (int i = objects.size() - 1; i >= 0; i--)
	{
		delete(objects[i]);
	}
	objects.clear();
}