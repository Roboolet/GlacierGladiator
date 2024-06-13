#include "InputSystem.h"
#include <iostream>
#include "Components.h"

void Player::OnUpdate(double _deltaTime)
{
	if (InputSystem::GetInstance().GetButton("Left")) {
		gameObject->position = gameObject->position + LeaVec2(-moveSpeed*_deltaTime, 0);
	}
	if (InputSystem::GetInstance().GetButton("Right")) {
		//gameObject->position = gameObject->position + LeaVec2(moveSpeed * _deltaTime, 0);
		//Rigidbody* rb = gameObject->GetComponent<Rigidbody>();
	}
	
}
