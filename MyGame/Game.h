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

	SDL_Texture* GetTexture(const std::string& fileName);

private:
	void LoadData();
	void UnloadData();
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	bool mIsRunning;
	bool mUpdatingActors;
	Uint32 mTicksCount;

	std::unordered_map<std::string, SDL_Texture*> mTextures;

	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;
	std::vector<class SpriteComponent*> mSprites;

	class Ship* mShip;
};
