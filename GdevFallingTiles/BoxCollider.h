#pragma once
#include "Component.h"
#include "GameObject.h"

// mostly just provides information to the physics checker
class BoxCollider : public Component {
public:
	virtual void OnUpdate(double _deltaTime) override;
	LeaVec2 topL, botL, topR, botR;
};