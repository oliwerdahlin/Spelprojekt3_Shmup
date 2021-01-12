#pragma once

namespace Tga2D
{
	class CSprite;
}
class Player : public Studio::GameObject
{
public:
	Player(Tga2D::CSprite* aSprite);
	~Player();
	void Update(float aDeltaTime);
	void Render();
private:
	float mySpeed;
	Tga2D::CSprite* mySprite;
	VECTOR2F myPosition;

};

