#pragma once
#include "CollisionObject.h"
#include <vector>
namespace Studio
{
	class Collider
	{
		std::vector<CollisionObject> myCollisionObjects;

	public:
		// Not implemented
		bool Intersects(const Collider& aCollider);
		// Not implemented
		bool Contains(const Collider& aCollider);
	};
}
