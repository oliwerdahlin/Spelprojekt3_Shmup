#pragma once
#include "Health.h"
// TODO: ^ Avoid this?
namespace Studio
{
	class GameObject
	{
	private:

		Sprite mySprite;
		Collider myCollider;
		Health myHealth;

	public:

		// Temporary accessor for mySprite. DO NOT USE IN RETAIL
		Sprite& GetSprite();	 // Temporary accesser
		// Temporary accessor for myHealth. DO NOT USE IN RETAIL
		Health& GetHealth();	 // Temporary accesser

		#pragma region Sprite Specific
		// TODO: Steal public stuff from Sprite.h
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

