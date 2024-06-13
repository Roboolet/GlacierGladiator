#include "Rigidbody.h"
#include "GameObject.h"
#include <iostream>

void Rigidbody::OnUpdate(double _deltaTime)
{
	velocity = velocity + LeaVec2(0, gravity * _deltaTime);

	LeaVec2 v = velocity * _deltaTime;
	velocity = velocity - (v * drag);

	gameObject->position = gameObject->position + velocity;
}
