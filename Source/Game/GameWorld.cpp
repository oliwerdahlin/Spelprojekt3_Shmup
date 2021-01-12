#include "stdafx.h"
#include "GameWorld.h"
#include<iostream>
#include "Player.h"
#include <tga2d/sprite/sprite.h>

CGameWorld::CGameWorld()
{
	myTga2dLogoSprite = nullptr;
	myPlayer = nullptr;
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
	SAFE_CREATE(myPlayer, Studio::Player(myTga2dLogoSprite));
}

//aIsPlaying is an atomic bool to close the gameplay thread
void CGameWorld::Update(float aDeltaTime, std::atomic<bool>& aIsPlaying)
{
	myPlayer->Update(aDeltaTime);
	myRenderer.RenderObject(myPlayer->GetRenderCommand());
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
