#include "stdafx.h"
#include "Bullet.h"
namespace Studio
{
	Bullet::Bullet(VECTOR2F aPosition, const float& aSpeed, VECTOR2F aDirection)
	{
		myPosition = aPosition;
		mySpeed = aSpeed;
		myDirection = aDirection.Normalize();
	}

	Bullet::~Bullet()
	{
	}

	void Bullet::Update()
	{
	}
}

