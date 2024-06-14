#include "InputSystem.h"
#include <iostream>
#include "Components.h"

void Player::OnAwaken()
{
	// this sucks
	rb = dynamic_cast<Rigidbody*>(gameObject->GetComponent(typeid(Rigidbody).name()));
	rb->gravity = 1;
}

void Player::OnUpdate(double _deltaTime)
{
	if (rb->collidedLastFrame) canJump = true;

	if (InputSystem::GetInstance().GetButton("Left")) {
		rb->AddForce(LeaVec2(-moveSpeed * _deltaTime, 0));
	}
	if (InputSystem::GetInstance().GetButton("Right")) {		
		rb->AddForce(LeaVec2(moveSpeed * _deltaTime, 0));
	}
	if (InputSystem::GetInstance().GetButton("Up") && canJump) {
		rb->velocity = LeaVec2(rb->velocity.x, jumpPower);
		canJump = false;
	}
	
}

Player::~Player()
{
	rb = nullptr;
}
