#include "stdafx.h"
Player::Player()
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
	if (GetAsyncKeyState(0x57) && myPosition.y > 0.05f)
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
	

	/*printf("\nX:%f", myPosition.x);
	printf("\nY:%f", myPosition.y);*/
}

void Player::Render()
{

}
