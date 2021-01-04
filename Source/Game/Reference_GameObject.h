#pragma once
#include "RenderCommand.h"

namespace Tga2D
{
	class CSprite;
}

class Reference_GameObject
{
public:

	Reference_GameObject();
	~Reference_GameObject();

	void Init(const CommonUtilities::Vector2f& aPos, const float aXDir, const float aYDir, const float aSpeed);
	void Update(const float aDeltaTime);
	const Tga2D::CSprite& GetSprite() const;
	const CommonUtilities::Vector2f& GetPosition() const;
	RenderCommand GetRenderCommand() const;

private:
	RenderCommand myRenderCommand;
	CommonUtilities::Vector2f myPosition;
	CommonUtilities::Vector2f myDirection;
	float mySpeed{};
	Tga2D::CSprite* mySprite;
};

