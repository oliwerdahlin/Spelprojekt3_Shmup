#pragma once
#include "GameObject.h"
namespace Tga2D
{
	class CSprite;
}
namespace Studio
{
	class Bullet : public GameObject
	{
	public:
		Bullet() = default;
		Bullet(VECTOR2F aPosition, const float& aSpeed, VECTOR2F aDirection, Tga2D::CSprite* aSprite);
		~Bullet();
		void Update(float aDeltaTime);

		VECTOR2F GetPosition();

		Studio::RenderCommand& GetRenderCommand();

	private:
		float mySpeed;

		Tga2D::CSprite* mySprite;

		VECTOR2F myPosition;
		VECTOR2F myDirection;
	};
}


