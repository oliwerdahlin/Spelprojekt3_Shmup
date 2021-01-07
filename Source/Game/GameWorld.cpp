#include "stdafx.h"
#include "GameWorld.h"
#include <tga2d/sprite/sprite.h>

#include<iostream>

CGameWorld::CGameWorld()
{
	myTga2dLogoSprite = nullptr;
}

CGameWorld::~CGameWorld() 
{
	delete myTga2dLogoSprite;
	myTga2dLogoSprite = nullptr;
}

void CGameWorld::Init()  
{
	myTga2dLogoSprite = new Tga2D::CSprite("sprites/tga_logo.dds");
	myTga2dLogoSprite->SetPivot({ 0.5f, 0.5f });
	myTga2dLogoSprite->SetPosition({ 0.5f, 0.5f });
}


void CGameWorld::Update(float /*aTimeDelta*/)
{ 	
	if (Studio::InputManager::GetInstance()->IsKeyPressed('D'))
	{
		std::cout << "D Pressed" << std::endl;
	}
	if (Studio::InputManager::GetInstance()->IsKeyDown('D'))
	{
		std::cout << "D key Down" << std::endl;
	}
	if (Studio::InputManager::GetInstance()->IsKeyUp('D'))
	{
		std::cout << "D key Up" << std::endl;
	}
	std::cout << "Delta Time: " << Studio::Timer::GetInstance()->TGetDeltaTime() << " Total Time: " << Studio::Timer::GetInstance()->TGetTotalTime() << std::endl;

}

void CGameWorld::Render()
{
	myTga2dLogoSprite->Render();
}