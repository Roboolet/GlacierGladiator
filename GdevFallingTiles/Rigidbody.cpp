#include "Rigidbody.h"

void Rigidbody::OnUpdate(double _deltaTime)
{
	gameObject->position = gameObject->position + velocity;
}
