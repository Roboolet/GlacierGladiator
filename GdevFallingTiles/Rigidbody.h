#pragma once
#include "LeaMath.h"
#include "Component.h"

class Rigidbody : public Component {
public:
	LeaVec2 velocity;
	float drag = 0.9;

	void AddForce(LeaVec2 _v) { velocity = velocity + _v; }
	virtual void OnUpdate(double _deltaTime) override;
};