#include "stdafx.h"
#include "RenderCommand.h"
#include <tga2d/sprite/sprite.h>
#include <iostream>

void RenderCommand::Update(CommonUtilities::Vector2f& aPos, Tga2D::CSprite* aSprite)
{
	myPosition = aPos;
	mySprite = aSprite;
	mySprite->SetPosition({ myPosition.x, myPosition.y });
}

void RenderCommand::Render()
{
	mySprite->Render();
}
