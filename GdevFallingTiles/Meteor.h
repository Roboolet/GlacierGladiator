#pragma once
#include "Component.h"
#include "Rigidbody.h"
#include "GameObject.h"

class Meteor : public Component {
public:
	virtual void OnAwaken() override;
	virtual void OnUpdate(double _deltaTime) override;

private:
	const float drift = 1;
	float randrift;
	Rigidbody* rb;
};