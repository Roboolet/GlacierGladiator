#include "BoxCollider.h"

void BoxCollider::OnUpdate(double _deltaTime)
{
	botL = gameObject->position - (gameObject->scale / 2);
	topR = gameObject->position + (gameObject->scale / 2);

	topL = LeaVec2(botL.x, topR.y);
	botR = LeaVec2(topR.x, botL.y);
}
