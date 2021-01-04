#include "stdafx.h"
#include "Reference_GameObject.h"
#include <tga2d/sprite/sprite.h>
#include <Vector2.hpp>


Reference_GameObject::Reference_GameObject()
{
	mySprite = nullptr;
}

Reference_GameObject::~Reference_GameObject()
{
	delete mySprite;
	mySprite = nullptr;
}

void Reference_GameObject::Init(const CommonUtilities::Vector2f& aPos, const float aXDir, const float aYDir, const float aSpeed)
{
	myDirection.x = aXDir / 100;
	myDirection.y = aYDir / 100;
	myPosition = aPos;
	mySpeed = aSpeed / 100;
	mySprite = nullptr;
	mySprite = new Tga2D::CSprite("Sprites/Kitteh.dds");
	mySprite->SetSizeRelativeToImage({0.15, 0.15});
	mySprite->SetPivot({0.5, 0.5});
	
}

void Reference_GameObject::Update(const float aDeltaTime)
{
	myPosition.x += myDirection.x * mySpeed * aDeltaTime;
	myPosition.y += myDirection.y * mySpeed * aDeltaTime;
	if (myPosition.x >= 1 || myPosition.x <= 0)
	{
		myDirection.x *= -1;
	}
	if (myPosition.y >= 1 || myPosition.y <= 0)
	{
		myDirection.y *= -1;
	}
	mySprite->SetPosition({ myPosition.x, myPosition.y });
	myRenderCommand.Update(myPosition, mySprite);
}

const Tga2D::CSprite& Reference_GameObject::GetSprite() const
{
	return *mySprite;
}

const CommonUtilities::Vector2f& Reference_GameObject::GetPosition() const
{
	return myPosition;
}

RenderCommand Reference_GameObject::GetRenderCommand() const
{
	return myRenderCommand;
}
