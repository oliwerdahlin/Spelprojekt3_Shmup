#include "stdafx.h"
#include "GameWorld.h"
#include <tga2d/sprite/sprite.h>

#include<iostream>

CGameWorld::CGameWorld()
{
	myTga2dLogoSprite = nullptr;

	SAFE_CREATE(myPlayer, Player());
}

CGameWorld::~CGameWorld() 
{
	delete myTga2dLogoSprite;
	myTga2dLogoSprite = nullptr;
}

void CGameWorld::Init()  
{
	myRenderer.Init();
	myTga2dLogoSprite = new Tga2D::CSprite("sprites/tga_logo.dds");
	myTga2dLogoSprite->SetPivot({ 0.5f, 0.5f });
	myTga2dLogoSprite->SetPosition({ 0.5f, 0.5f });
}



//aIsPlaying is an atomic bool to close the gameplay thread
void CGameWorld::Update(float aDeltaTime, std::atomic<bool>& aIsPlaying)
{
	myPlayer->Update(aDeltaTime);
	
}



void CGameWorld::Render()
{
	myTga2dLogoSprite->Render();
	myRenderer.Render();
}

void CGameWorld::SwapBuffers()
{
	myRenderer.SwapBuffers();
}
