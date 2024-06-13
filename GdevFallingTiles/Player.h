#pragma once
#include "GameObject.h"
#include "Component.h"

class Player : public Component {
public:
	virtual void OnAwaken() override;
	virtual void OnUpdate(double _deltaTime) override;

private:
	const float moveSpeed = 30;
};