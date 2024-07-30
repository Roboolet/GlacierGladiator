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
		canJump = true;

		TextRenderer* t = dynamic_cast<TextRenderer*>(gameObject->scene->Find("score")
			->GetComponent(typeid(TextRenderer).name()));
		// if above a certain height, gain score (because you break meteors)
		if (gameObject->position.y < 30 && gameObject->scene->gamestate == Gamestate::Playing) {			

			scoreMult++;
			score += 100*scoreMult;
			t->text = "Score: " + std::to_string(score) + " ***" + std::to_string(scoreMult);

			// also launch yourself!
			rb->velocity = LeaVec2(-rb->velocity.x, -rb->velocity.y + jumpPower);
		}
		// landing on ground
		else {
			scoreMult = 0;
			t->text = "Score: " + std::to_string(score);
		}
	}

	// change color based on double jump
	BoxRenderer* rend = dynamic_cast<BoxRenderer*>(gameObject->
	GetComponent(typeid(BoxRenderer).name()));
	if (canJump) {
		rend->fillColor = sf::Color(110, 150, 255, 255);
	}
	else {
		rend->fillColor = sf::Color(90, 120, 120, 255);
	}

	// input checks
	if (InputSystem::GetInstance().GetButton("Left")) {
		rb->AddForce(LeaVec2(-moveSpeed * _deltaTime, 0));
	}
	if (InputSystem::GetInstance().GetButton("Right")) {		
		rb->AddForce(LeaVec2(moveSpeed * _deltaTime, 0));
	}
	if (InputSystem::GetInstance().GetButtonDown("Up") && canJump) {
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

Player::Player()
{
	moveSpeed = 2;
	jumpPower = -0.6;
	score = 0;
	scoreMult = 1;
	canJump = false;
}

Player::~Player()
{
	rb = nullptr;
}
