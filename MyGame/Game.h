#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include "SDL/SDL.h"

class Game
{
public:
	Game();
	
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	class Texture* GetTexture(const std::string& fileName);

	void AddAsteroid(class Asteroid* ast);
	void RemoveAsteroid(class Asteroid* ast);
	std::vector<class Asteroid*>& GetAsteroids() { return mAsteroids; }

private:
	void LoadData();
	void UnloadData();
	bool LoadShaders();
	void CreateSpriteVerts();
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	SDL_Window* mWindow;
	SDL_GLContext mContext;
	bool mIsRunning;
	bool mUpdatingActors;
	Uint32 mTicksCount;

	std::unordered_map<std::string, class Texture*> mTextures;

	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;
	std::vector<class SpriteComponent*> mSprites;

	class Shader* mSpriteShader;
	class VertexArray* mSpriteVerts;

	class Ship2* mShip;
	std::vector<class Asteroid*> mAsteroids;
};
