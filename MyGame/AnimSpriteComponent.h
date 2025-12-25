#pragma once

#include <vector>

#include "Actor.h"
#include "SDL/SDL.h"
#include "SpriteComponent.h"

class AnimSpriteComponent : public SpriteComponent
{
public:
	AnimSpriteComponent(Actor* owner, int drawOrder = 100);

	void Update(float deltaTime) override;
	void SetAnimTextures(const std::vector<class Texture*>& textures);

	float GetAnimFPS() const { return mAnimFPS; }
	void SetAnimFPS(float fps) { mAnimFPS = fps; }

private:
	std::vector<class Texture*> mAnimTextures;

	float mCurrFrame;
	float mAnimFPS;
};
