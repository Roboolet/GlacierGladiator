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
	const float moveSpeed = 4;
	Rigidbody* rb;
};