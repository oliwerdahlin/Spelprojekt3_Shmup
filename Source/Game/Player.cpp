#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"

namespace Studio
{
	Player::Player(Tga2D::CSprite* aSprite) : 
		Player::GameObject(aSprite)
	{
		myPosition = { 0.5f, 0.5f };
		mySpeed = 0.3f;
	}

	Player::~Player()
	{

	}

	void Player::Update(float aDeltaTime)
	{
		//W
		if (Studio::InputManager::GetInstance()->IsKeyDown('W') && myPosition.y > 0.05f)
		{
			myPosition.y -= mySpeed * aDeltaTime;
		}
		//A
		if (GetAsyncKeyState(0x41) && myPosition.x > 0.05f)
		{
			myPosition.x -= mySpeed * aDeltaTime;
		}
		//S
		if (GetAsyncKeyState(0x53) && myPosition.y < 9.95f)
		{
			myPosition.y += mySpeed * aDeltaTime;
		}
		//D
		if (GetAsyncKeyState(0x44) && myPosition.x < 9.95f)
		{
			myPosition.x += mySpeed * aDeltaTime;
		}
		Player::GameObject::Update(myPosition);

		/*printf("\nX:%f", myPosition.x);
		printf("\nY:%f", myPosition.y);*/
	}

	Studio::RenderCommand& Player::GetRenderCommand()
	{
		return Player::GameObject::GetRenderCommand();
	}
}

