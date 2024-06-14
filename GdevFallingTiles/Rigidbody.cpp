#include "Rigidbody.h"
#include "GameObject.h"
#include <iostream>

Rigidbody::Rigidbody(BodyType _bt) : bodyType(_bt)
{
}

void Rigidbody::OnUpdate(double _deltaTime)
{
	if (bodyType != BodyType::Static) {
		velocity = velocity + LeaVec2(0, gravity * _deltaTime);

		LeaVec2 v = velocity * _deltaTime;
		velocity = velocity - (v * drag);

		gameObject->position = gameObject->position + velocity;
	}
}
