#include "Asteroid.h"
#include "CircleComponent.h"
#include "Game.h"
#include "MoveComponent.h"
#include "Random.h"
#include "Renderer.h"
#include "SpriteComponent.h"
#include "Texture.h"

Asteroid::Asteroid(Game* game)
	: Actor(game)
{
	// Initialize to random position/orientation
	Vector3 randPos = Random::GetVector(Vector3(-512.0f, -384.0f, 0.0f), Vector3(512.0f, 384.0f, 0.0f));
	SetPosition(randPos);

	Quaternion randRot = Quaternion(Vector3::UnitZ, Random::GetFloatRange(0.0f, Math::TwoPi));
	SetRotation(randRot);

	// Create a sprite component
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetRenderer()->GetTexture("Assets/Asteroid.png"));

	// Create a move component, and set a forward speed
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(150.0f);

	// Create a circle component (for collision)
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);

	// Add to mAsteroids in game
	game->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
	GetGame()->RemoveAsteroid(this);
}