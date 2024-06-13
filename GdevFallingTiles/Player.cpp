#include "InputSystem.h"
#include <iostream>
#include "Components.h"

void Player::OnUpdate(double _deltaTime)
{
	if (InputSystem::GetInstance().GetButton("Left")) {
		gameObject->position = gameObject->position + LeaVec2(-moveSpeed*_deltaTime, 0);
	}
	if (InputSystem::GetInstance().GetButton("Right")) {
		// this sucks
		Rigidbody* rb = dynamic_cast<Rigidbody*>(gameObject->GetComponent(typeid(Rigidbody).name()));
		rb->AddForce(LeaVec2(moveSpeed * _deltaTime, 0));
	}
	
}
