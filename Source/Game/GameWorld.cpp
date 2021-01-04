#include "stdafx.h"
#include "GameWorld.h"
#include <atomic>
#include <CURandom.h>
#include <chrono>

CGameWorld::CGameWorld(CommonUtilities::InputManager* aInputManager, CommonUtilities::Timer* aTimer) :
	myInputManager(aInputManager),
	myGameTimer(aTimer)
{
}

CGameWorld::~CGameWorld() 
{
}

void CGameWorld::Init()  
{
	//Creating 1000 example objects
	for (int i = 0; i < 1000; i++)
	{
		myExample_GameObjects.push_back(new Reference_GameObject);
	}
	for (Reference_GameObject* exampleObject : myExample_GameObjects)
	{
		exampleObject->Init(CommonUtilities::Vector2f(0.5, 0.5),
			CommonUtilities::RandNumbInRange(1, 100), 
			CommonUtilities::RandNumbInRange(1, 100), 
			CommonUtilities::RandNumbInRange(1, 100));
	}
	

	//Initializing the render buffers 
	myReadFromBuffer = &myRenderBuffers[1];
	myWriteToBuffer = &myRenderBuffers[0];
}


//Gameplay thread
void CGameWorld::Update(float aTimeDelta, std::atomic<bool>& aIsPlaying)
{ 	
	for (int i = static_cast<int>(myExample_GameObjects.size()); i-- > 0; )
	{
		//Here is the game logic of the example object
		myExample_GameObjects[i]->Update(aTimeDelta);

		//This is what pushes the render command to the buffer
		GetWriteToBuffer().push_back(myExample_GameObjects[i]->GetRenderCommand());
	}

	//For stopping the gameplay thread
	if (myInputManager->IsKeyDown('D'))
	{
		aIsPlaying = false;
	}
}


//Render Thread
void CGameWorld::Render()
{
	for (int i = static_cast<int>(myReadFromBuffer->size()); i-- > 0;)
	{
		GetReadFromBuffer()[i].Render();
	}
}





//All below of here is for doing the buffer swaps
void CGameWorld::SwapBuffers() {
	std::vector<RenderCommand>* temp_buffer_pointer = &(*myWriteToBuffer);
	myWriteToBuffer = &(*myReadFromBuffer);
	myReadFromBuffer = &(*temp_buffer_pointer);
	myWriteToBuffer->clear();
}

std::vector<RenderCommand>& CGameWorld::GetReadFromBuffer() const 
{
	return (*myReadFromBuffer);
}
std::vector<RenderCommand>& CGameWorld::GetWriteToBuffer()
{
	return (*myWriteToBuffer);
}
