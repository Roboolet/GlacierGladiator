#pragma once
#include "Component.h"
#include "GameObject.h"

class MeteorSpawner : public Component {
public:
	MeteorSpawner(int _amount, double _startingDelay);
	virtual void OnAwaken() override;
	virtual void OnUpdate(double _deltaTime) override;

private:
	double delay;
	double lastSpawnTime;
	int meteorsLeft;
	bool hasWon;
	void SpawnMeteor();
};