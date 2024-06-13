#include "Rigidbody.h"
#include "GameObject.h"

void Rigidbody::OnUpdate(double _deltaTime)
{
	LeaVec2 v = velocity * _deltaTime;
	velocity = velocity - (v * drag);
	gameObject->position = gameObject->position + velocity;
}
