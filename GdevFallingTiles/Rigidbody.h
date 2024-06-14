#pragma once
#include "LeaMath.h"
#include "Component.h"

// - Static bodies do not move
// - Kinematic bodies will not receive push forces from physics-updates,
// but will still have gravity and such
// - Dynamic receive all forces
enum BodyType{ Static, Kinematic, Dynamic};

class Rigidbody : public Component {
public:
	Rigidbody(BodyType);

	LeaVec2 velocity;
	BodyType bodyType = BodyType::Static;
	float drag = 0.95;
	float gravity = 0.5;

	// i don't know if there's something similar to C# events,
	// but the deadline is a little too close to go and learn
	bool collidedLastFrame = false;

	void AddForce(LeaVec2 _v) { velocity = velocity + _v; }
	virtual void OnUpdate(double _deltaTime) override;
};