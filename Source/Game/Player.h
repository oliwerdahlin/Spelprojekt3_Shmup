#pragma once
#include "GameObject.h"
namespace Tga2D
{
	class CSprite;
}
namespace Studio
{
	class Player : public GameObject
	{
	public:
		Player(Tga2D::CSprite* aSprite);
		~Player();
		void Update(float aDeltaTime);
		Studio::RenderCommand& GetRenderCommand();
	private:
		float mySpeed;
		VECTOR2F myPosition;

	};
}


