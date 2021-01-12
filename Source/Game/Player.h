#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <vector>
#include "Renderer.h"
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
		void Shoot(float aDeltaTime);

		std::vector<Bullet*>& GetBullets();

		Studio::RenderCommand& GetRenderCommand();
	private:
		float mySpeed;
		float myShootCooldown;
		std::vector<Bullet*> myBullets;

		Tga2D::CSprite* mySprite;
		Tga2D::CSprite* myBulletSprite;
		VECTOR2F myPosition;

	};
}


