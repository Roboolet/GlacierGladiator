#include "Components.h"
#include "Scene.h"

typedef std::vector<Component*> compVec;

MeteorSpawner::MeteorSpawner(int _amount, double _startingDelay)
{
}

void MeteorSpawner::OnAwaken()
{
}

void MeteorSpawner::OnUpdate(double _deltaTime)
{
	SpawnMeteor();
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
