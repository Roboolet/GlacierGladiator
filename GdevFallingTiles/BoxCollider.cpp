#include "BoxCollider.h"

void BoxCollider::OnUpdate(double _deltaTime)
{
	topL = gameObject->position;
	botR = gameObject->position + gameObject->scale;
	width = gameObject->scale.x;
	height = gameObject->scale.y;
}
