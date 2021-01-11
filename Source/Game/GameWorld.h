#pragma once
#include "Renderer.h"

class Player;
namespace Tga2D
{
	class CSprite;
	class FBXModel;
	class CAudio;
}

class CGameWorld
{
public:
	CGameWorld(); 
	~CGameWorld();

	void Init();
	void Update(float aDeltaTime, std::atomic<bool>& aIsPlaying);
	void Render();
	void SwapBuffers();
private:
	Renderer myRenderer;
	Tga2D::CSprite* myTga2dLogoSprite;
	Player* myPlayer;
};