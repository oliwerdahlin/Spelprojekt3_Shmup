#pragma once
#include "Health.h"
#include "RenderCommand.h"
#include "Sprite.h"
#include "Collider.h"

// TODO: ^ Avoid this?
namespace Tga2D
{
	class CSprite;
}
namespace Studio
{
	class GameObject
	{
	private:
		Sprite mySprite;
		Collider myCollider;
		Health myHealth;
		RenderCommand myRenderCommand;

	public:
		void Update(const Tga2D::Vector2f& aPos);
		GameObject(const Tga2D::Vector2f& aPos, Tga2D::CSprite* aSprite);
		// Temporary accessor for mySprite. DO NOT USE IN RETAIL
		Sprite& GetSprite();	 // Temporary accesser
		// Temporary accessor for myHealth. DO NOT USE IN RETAIL
		Health& GetHealth();	 // Temporary accesser

		#pragma region Sprite Specific
		// TODO: Steal public stuff from Sprite.h
		const Studio::RenderCommand& GetRenderCommand() const;
		#pragma endregion

		#pragma region Collider Specific
		bool Intersects(const GameObject& aGameObject);
		bool Contains(const GameObject& aGameObject);
		#pragma endregion

		#pragma region Health Specific
		// TODO: Steal public stuff from Health.h
		#pragma endregion
	};
}

