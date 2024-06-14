#include "Components.h"

void Meteor::OnAwaken()
{
	// this sucks
	rb = dynamic_cast<Rigidbody*>(gameObject->GetComponent(typeid(Rigidbody).name()));
	float randDrift = (((double)rand() - 100) / (RAND_MAX)) * drift - drift / 2;
	rb->AddForce(LeaVec2(randDrift, 0));
}

void Meteor::OnUpdate(double _deltaTime)
{
}
