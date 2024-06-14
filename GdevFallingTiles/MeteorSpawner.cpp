#include "Components.h"
#include "Scene.h"

typedef std::vector<Component*> compVec;

MeteorSpawner::MeteorSpawner(int _amount, double _startingDelay) : delay(_startingDelay), meteorsLeft(_amount)
{
}

void MeteorSpawner::OnAwaken()
{
}

void MeteorSpawner::OnUpdate(double _deltaTime)
{
	if (gameObject->scene->gamestate == Gamestate::Playing) {
		if (meteorsLeft > 0) {
			if (lastSpawnTime + delay < gameObject->scene->timeSinceStart) {
				SpawnMeteor();
				meteorsLeft--;
				lastSpawnTime = gameObject->scene->timeSinceStart;
			}
		}
		else if (lastSpawnTime + 3000000000 < gameObject->scene->timeSinceStart) {

			gameObject->scene->gamestate = Gamestate::Won;
			gameObject->scene->Instantiate("winText", LeaVec2(-72, -40), LeaVec2(15, 15), compVec{
			new TextRenderer("You win!! Great job", 12) });
		}
	}
}

void MeteorSpawner::SpawnMeteor()
{
	float randX = ((((double)rand() - 100) / (RAND_MAX)) * gameObject->scale.x) - gameObject->scale.x/2;
	gameObject->scene->Instantiate("meteor", LeaVec2(randX, gameObject->position.y), LeaVec2(15, 15), compVec{
		new BoxRenderer(100, 60, sf::Color(255,100,100,255), sf::BlendAdd),
		new Rigidbody(BodyType::Kinematic),
		new BoxCollider(),
		new Meteor() });
}
