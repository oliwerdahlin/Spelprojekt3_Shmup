#pragma once
namespace Tga2D
{
	class CSprite;
}
class Player : Studio::GameObject
{
public:
	Player();
	~Player();
	void Update(float aDeltaTime);
	void Render();
private:
	float mySpeed;

	VECTOR2F myPosition;

};

