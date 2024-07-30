#pragma once
#include "Component.h"
#include "Rigidbody.h"
#include "GameObject.h"

class Meteor : public Component {
public:
	virtual void OnAwaken() override;
	virtual void OnUpdate(double _deltaTime) override;
	Meteor();
	virtual ~Meteor();

private:
	const float drift;
	float randrift;
	Rigidbody* rb;
};