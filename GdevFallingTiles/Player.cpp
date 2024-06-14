#include "InputSystem.h"
#include <iostream>
#include "Components.h"
#include "Scene.h"

void Player::OnAwaken()
{
	// this sucks
	rb = dynamic_cast<Rigidbody*>(gameObject->GetComponent(typeid(Rigidbody).name()));
	rb->gravity = 1;
}

void Player::OnUpdate(double _deltaTime)
{
	if (rb->collidedLastFrame) {		
		// if above a certain height, gain score (because you break meteors)
		if (gameObject->position.y < 30 && gameObject->scene->gamestate == Gamestate::Playing) {
			TextRenderer* t = dynamic_cast<TextRenderer*>(gameObject->scene->Find("score")
				->GetComponent(typeid(TextRenderer).name()));
			score += 100;
			t->text = "Score: " + std::to_string(score);

			// also launch yourself!
			rb->velocity = LeaVec2(rb->velocity.x, jumpPower);
		}
		// landing on ground
		else {
			canJump = true;
		}
	}

	// input checks
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

	// looping
	if(gameObject->position.x < -102){
		gameObject->position = LeaVec2(101, gameObject->position.y);
	}
	else if (gameObject->position.x > 102) {
		gameObject->position = LeaVec2(-101, gameObject->position.y);
	}
	
}

Player::~Player()
{
	rb = nullptr;
}
