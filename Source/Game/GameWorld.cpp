#include "stdafx.h"
#include "GameWorld.h"
#include<iostream>
#include "Player.h"
#include <tga2d/sprite/sprite.h>
#include "RendererAccessor.h"

CGameWorld::CGameWorld()
{
	myTga2dLogoSprite = nullptr;
	myPlayer = nullptr;
}

CGameWorld::~CGameWorld() 
{
	delete myTga2dLogoSprite;
	myTga2dLogoSprite = nullptr;
	SAFE_DELETE(myPlayer);
}

void CGameWorld::MoveLogo()
{
	myTga2dLogoSprite->SetPosition({ 0.8f,0.5f });
}

void CGameWorld::Init()  
{
	myRenderer.Init();
	Studio::RendererAccessor::SetInstance(&myRenderer);
	myTga2dLogoSprite = new Tga2D::CSprite("sprites/tga_logo.dds");
	myTga2dLogoSprite->SetPivot({ 0.5f, 0.5f });
	myTga2dLogoSprite->SetPosition({ 0.5f, 0.5f });
	SAFE_CREATE(myPlayer, Studio::Player(new Tga2D::CSprite("sprites/debugpixel.dds")));
	
}

//aIsPlaying is an atomic bool to close the gameplay thread
void CGameWorld::Update(float aDeltaTime, std::atomic<bool>& aIsPlaying)
{
	myPlayer->Update(aDeltaTime);
	Studio::RendererAccessor::GetInstance()->Render(*myPlayer);

	for (int i = 0; i < myPlayer->GetBullets().size(); i++)
	{
		Studio::RendererAccessor::GetInstance()->Render(*myPlayer->GetBullets()[i]);
	}
}

void CGameWorld::Render()
{
	//myTga2dLogoSprite->Render();
	myRenderer.Render();
}

void CGameWorld::SwapBuffers()
{
	myRenderer.SwapBuffers();
}


