#include "MoveComponent.h"
#include "Actor.h"
#include "Math.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
	: Component(owner, updateOrder)
	, mAngularSpeed(0.0f)
	, mForwardSpeed(0.0f)
{
}

void MoveComponent::Update(float deltaTime)
{
	if (!Math::NearZero(mAngularSpeed))
	{
		float angle = mAngularSpeed * deltaTime;
		Quaternion inc(Vector3::UnitZ, angle);
		
		Quaternion rot = Quaternion::Concatenate(mOwner->GetRotation(), inc);

		mOwner->SetRotation(rot);
	}

	if (!Math::NearZero(mForwardSpeed))
	{
		Vector3 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime;

		if (pos.x < -512.0f)
		{
			pos.x = 510.0f;
		}
		else if (pos.x > 512.0f)
		{
			pos.x = -510.0f;
		}

		if (pos.y < -384.0f)
		{
			pos.y = 382.0f;
		}
		else if (pos.y > 384.0f)
		{
			pos.y = -382.0f;
		}

		mOwner->SetPosition(pos);
	}
}