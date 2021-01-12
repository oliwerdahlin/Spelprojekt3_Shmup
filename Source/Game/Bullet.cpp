#include "stdafx.h"
#include "Bullet.h"
#include "tga2d/sprite/sprite.h"
namespace Studio
{
	Bullet::Bullet(VECTOR2F aPosition, const float& aSpeed, VECTOR2F aDirection, Tga2D::CSprite* aSprite) : 
		Bullet::GameObject(aSprite)
	{
		printf("%f", myPosition.x);
		myPosition = aPosition;
		mySpeed = aSpeed;
		myDirection = aDirection.Normalize();

		SAFE_CREATE(mySprite, Tga2D::CSprite(*aSprite));
	}

	Bullet::~Bullet()
	{
		SAFE_DELETE(mySprite);
	}

	void Bullet::Update(float aDeltaTime)
	{
		myPosition.x += mySpeed * aDeltaTime;

		Bullet::GameObject::Update(myPosition);
	}

	VECTOR2F Bullet::GetPosition()
	{
		return myPosition;
	}
	Studio::RenderCommand& Bullet::GetRenderCommand()
	{
		return Bullet::GameObject::GetRenderCommand();
	}
}

