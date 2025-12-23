#pragma once

#include "Actor.h"

class Ship2 : public Actor
{
public:
	Ship2(class Game* game);

	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* keyState) override;

private:
	float mLaserCooldown;
};
