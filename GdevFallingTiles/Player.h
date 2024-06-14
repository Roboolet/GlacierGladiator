#pragma once
#include "Component.h"
#include "Rigidbody.h"
#include "GameObject.h"

class Player : public Component {
public:
	virtual void OnAwaken() override;
	virtual void OnUpdate(double _deltaTime) override;

	virtual ~Player();

private:
	const float moveSpeed = 2;
	const float jumpPower = -0.6;
	bool canJump = false;
	Rigidbody* rb;
};