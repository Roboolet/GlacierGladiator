#pragma once
#include "Component.h"
#include "Rigidbody.h"
#include "GameObject.h"

class Player : public Component {
public:
	virtual void OnAwaken() override;
	virtual void OnUpdate(double _deltaTime) override;

	Player();
	virtual ~Player();

private:
	float moveSpeed;
	float jumpPower = -0.6;

	int score;
	int scoreMult;
	bool canJump;
	Rigidbody* rb;
};