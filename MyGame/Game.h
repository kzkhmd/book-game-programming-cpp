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

	class Renderer* GetRenderer() { return mRenderer; }

	void AddAsteroid(class Asteroid* ast);
	void RemoveAsteroid(class Asteroid* ast);
	std::vector<class Asteroid*>& GetAsteroids() { return mAsteroids; }

private:
	void LoadData();
	void UnloadData();
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	bool mIsRunning;
	bool mUpdatingActors;
	Uint32 mTicksCount;

	class Renderer* mRenderer;

	class CameraActor* mCameraActor;

	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;

	std::vector<class Asteroid*> mAsteroids;
};
