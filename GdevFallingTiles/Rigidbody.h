#pragma once
#include "LeaMath.h"
#include "Component.h"

class Rigidbody : public Component {
public:
	LeaVec2 velocity;

	void AddForce(LeaVec2 _v) { velocity = velocity + _v; }
	virtual void OnUpdate(double _deltaTime) override;
};