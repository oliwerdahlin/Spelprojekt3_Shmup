#include "stdafx.h"
namespace Studio
{
	Sprite& Studio::GameObject::GetSprite()
	{
		return mySprite;
	}

	Collider& Studio::GameObject::GetCollider()
	{
		return myCollider;
	}

	Health& Studio::GameObject::GetHealth()
	{
		return myHealth;
	}

	bool GameObject::Intersects(const GameObject& aGameObject)
	{
		return myCollider.Intersects(aGameObject.myCollider);
	}
	bool GameObject::Contains(const GameObject& aGameObject)
	{
		return myCollider.Contains(aGameObject.myCollider);
	}
}
