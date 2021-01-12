#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "tga2d/sprite/sprite.h"

namespace Studio
{
	Player::Player(Tga2D::CSprite* aSprite) : 
		Player::GameObject(aSprite)
	{
		myPosition = { 0.5f, 0.5f };
		mySpeed = 0.3f;
		myShootCooldown = 0.0f;
		mySprite = aSprite;
		mySprite->SetSizeRelativeToImage({ 50, 50 });
		mySprite->SetPivot({ 0.5f, 0.5f });
		SAFE_CREATE(myBulletSprite, Tga2D::CSprite("sprites/debugpixel.dds"));
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
		if (Studio::InputManager::GetInstance()->IsKeyDown('A') && myPosition.x > 0.05f)
		{
			myPosition.x -= mySpeed * aDeltaTime;
		}
		//S
		if (Studio::InputManager::GetInstance()->IsKeyDown('S') && myPosition.y < 0.95f)
		{
			myPosition.y += mySpeed * aDeltaTime;
		}
		//D
		if (Studio::InputManager::GetInstance()->IsKeyDown('D') && myPosition.x < 0.95f)
		{
			myPosition.x += mySpeed * aDeltaTime;
		}
		//D
		if (Studio::InputManager::GetInstance()->IsKeyDown(VK_SPACE))
		{
			Shoot(aDeltaTime);
		}

		Player::GameObject::Update(myPosition);

		for (int i = 0; i < myBullets.size(); i++)
		{
			myBullets[i]->Update(aDeltaTime);

			if (myBullets[i]->GetPosition().x > 1.0f)
			{
				myBullets.erase(myBullets.begin() + i);
			}

		}
	}

	void Player::Shoot(float aDeltaTime)
	{
		myShootCooldown += aDeltaTime;
		if (GetAsyncKeyState(VK_SPACE) && myShootCooldown > 0.1f)
		{
			myBullets.push_back(new Bullet(myPosition, 1.0f, { 1,0 }, myBulletSprite));
			myShootCooldown = 0;
		}
	}

	std::vector<Bullet*>& Player::GetBullets()
	{
		return myBullets;
	}

	Studio::RenderCommand& Player::GetRenderCommand()
	{
		return Player::GameObject::GetRenderCommand();
	}
}

