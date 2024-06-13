#pragma once
#include "Component.h"
#include "GameObject.h"

class Player : public Component {
public:
	virtual void OnUpdate(double _deltaTime) override;

private:
	const float moveSpeed = 30;
};