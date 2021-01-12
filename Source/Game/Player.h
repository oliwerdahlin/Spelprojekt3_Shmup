#pragma once
#include "GameObject.h"
namespace Tga2D
{
	class CSprite;
}
namespace Studio
{
	class Player : GameObject
	{
	public:
		Player();
		~Player();
		void Update(float aDeltaTime);
		void Render();
	private:
		float mySpeed;

		VECTOR2F myPosition;

	};
}


