#include "stdafx.h"

namespace Studio
{
	void Collider::AddColliderObject(CollisionObject& aCollisionObject)
	{
		myCollisionObjects.push_back(aCollisionObject);
	}

	bool Collider::Intersects(const Collider& aCollider)
	{
		return false;
	}

	bool Collider::Contains(const Collider& aCollider)
	{
		return false;
	}
	bool Collider::CircleToCircleCollision(CollisionObject& aFirstCollisionObject, CollisionObject& aSecondCollisionObject)
	{
		float deltaX = aFirstCollisionObject.GetPosition().x - aSecondCollisionObject.GetPosition().x;
		float deltaY = aFirstCollisionObject.GetPosition().y - aSecondCollisionObject.GetPosition().y;

		float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
		
		if (distance < aFirstCollisionObject.GetRadius() + aSecondCollisionObject.GetRadius())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Collider::CircleToAABBCollision(CollisionObject& aCircleCollisionObject, CollisionObject& anAABBCollisionObject)
	{
		return false;
	}
	bool Collider::AABBToAABBCollision(CollisionObject& aFirstCollisionObject, CollisionObject& aSecondCollisionObject)
	{
		return false;
	}
}