#include "Player.h"
#include "InputSystem.h"
#include <iostream>

void Player::OnAwaken()
{
}

void Player::OnUpdate(double _deltaTime)
{
	if (InputSystem::GetInstance().GetButton("Left")) {
		gameObject->position = gameObject->position + LeaVec2(-moveSpeed*_deltaTime, 0);
	}
	if (InputSystem::GetInstance().GetButton("Right")) {
		gameObject->position = gameObject->position + LeaVec2(moveSpeed * _deltaTime, 0);
	}
	
}
