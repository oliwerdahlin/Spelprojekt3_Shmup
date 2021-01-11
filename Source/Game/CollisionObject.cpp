#include "stdafx.h"
#include "CollisionObject.h"

Studio::CollisionObject::CollisionObject()
{
	myCollisionType = CollisionType::NoCollider;
}

Studio::CollisionObject::CollisionObject(Tga2D::Vector2f aPosition, Tga2D::Vector2f aColliderSize)
{
	myCollisionType = CollisionType::BoxCollider;
	myWidth = aColliderSize.x;
	myHeight = aColliderSize.y;
	myPosition = aPosition;
}

Studio::CollisionObject::CollisionObject(Tga2D::Vector2f aPosition, float aRadius)
{
	myCollisionType = CollisionType::CircleCollider;
	myRadius = aRadius;
	myPosition = aPosition;
}

float const Studio::CollisionObject::GetWidth()
{
	return myWidth;
}

float const Studio::CollisionObject::GetHeight()
{
	return myHeight;
}

float const Studio::CollisionObject::GetRadius()
{
	return myRadius;
}

Studio::CollisionType& Studio::CollisionObject::GetColliderType()
{
	return myCollisionType;
}

Tga2D::Vector2f Studio::CollisionObject::GetPosition()
{
	return myPosition;
}
