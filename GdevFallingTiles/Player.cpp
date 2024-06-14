#include "InputSystem.h"
#include <iostream>
#include "Components.h"

void Player::OnAwaken()
{
	// this sucks
	rb = dynamic_cast<Rigidbody*>(gameObject->GetComponent(typeid(Rigidbody).name()));
	rb->gravity = 1;
	rb->bodyType = BodyType::Dynamic;
}

void Player::OnUpdate(double _deltaTime)
{
	if (InputSystem::GetInstance().GetButton("Left")) {
		rb->AddForce(LeaVec2(-moveSpeed * _deltaTime, 0));
	}
	if (InputSystem::GetInstance().GetButton("Right")) {		
		rb->AddForce(LeaVec2(moveSpeed * _deltaTime, 0));
	}
	if (InputSystem::GetInstance().GetButtonDown("Up")) {
		rb->velocity = LeaVec2(rb->velocity.x, jumpPower);
	}
	
}

Player::~Player()
{
	rb = nullptr;
}
