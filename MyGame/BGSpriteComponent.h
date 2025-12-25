#pragma once

#include <vector>
#include "SDL/SDL.h"
#include "SpriteComponent.h"
#include "Math.h"

class BGSpriteComponent : public SpriteComponent
{
public:
	BGSpriteComponent(class Actor* owner, int drawOrder = 10);

	void Update(float deltaTime) override;

	void SetBGTextures(const std::vector<class Texture*>& textures);
	void SetScreenSize(const Vector2& size) { mScreenSize = size; }
	void SetScrollSpeed(float speed) { mScrollSpeed = speed; }
	float GetScrollSpeed() const { return mScrollSpeed; }

private:
	struct BGTexture
	{
		class Texture* mTexture;
		Vector2 mOffset;
	};

	std::vector<BGTexture> mBGTextures;
	
	Vector2 mScreenSize;
	float mScrollSpeed;
};
