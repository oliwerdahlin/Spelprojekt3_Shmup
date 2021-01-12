#include "stdafx.h"
#include <tga2d/sprite/sprite.h>
#include "Bullet.h"

Bullet::Bullet(VECTOR2F aPosition, const float &aSpeed, VECTOR2F aDirection):
	Bullet::GameObject(aPosition, mySprite)
{
	mySprite = new Tga2D::CSprite("sprites/debugpixel.dds");
	myPosition = aPosition;
	mySpeed = aSpeed;
	myDirection = aDirection.Normalize();
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
}
