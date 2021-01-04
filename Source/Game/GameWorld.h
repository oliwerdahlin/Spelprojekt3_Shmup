#pragma once
#include <InputManager.h>
#include <Timer.h>
#include "Reference_GameObject.h"
#include <vector>
#include <array>



namespace Tga2D
{
	class CSprite;
	class FBXModel;
	class CAudio;
}

class CGameWorld
{
public:
	CGameWorld(CommonUtilities::InputManager* aInputManager, CommonUtilities::Timer* aTimer);
	~CGameWorld();

	void Init();
	void Update(float aTimeDelta, std::atomic<bool>& aIsPlaying);
	void Render();
	void SwapBuffers();

private:
	std::vector<RenderCommand>& GetReadFromBuffer() const;
	std::vector<RenderCommand>& GetWriteToBuffer();
	std::vector<Reference_GameObject*> myExample_GameObjects;

	CommonUtilities::InputManager* myInputManager;
	CommonUtilities::Timer* myGameTimer;
	
	

	std::array<std::vector<RenderCommand>, 2> myRenderBuffers;
	std::vector<RenderCommand>* myWriteToBuffer;
	std::vector<RenderCommand>* myReadFromBuffer;
};