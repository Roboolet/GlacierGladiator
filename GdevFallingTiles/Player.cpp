#include "InputSystem.h"
#include <iostream>
#include "Components.h"

void Player::OnAwaken()
{
	// this sucks
	rb = dynamic_cast<Rigidbody*>(gameObject->GetComponent(typeid(Rigidbody).name()));
}

void Player::OnUpdate(double _deltaTime)
{
	if (InputSystem::GetInstance().GetButton("Left")) {
		rb->AddForce(LeaVec2(-moveSpeed * _deltaTime, 0));
	}
	if (InputSystem::GetInstance().GetButton("Right")) {		
		rb->AddForce(LeaVec2(moveSpeed * _deltaTime, 0));
	}
	
}

Player::~Player()
{
	rb = nullptr;
}
