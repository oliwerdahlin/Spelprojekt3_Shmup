#pragma once
#include <Vector2.hpp>


namespace Tga2D
{
	class CSprite;
}

class RenderCommand
{
public:
	RenderCommand() = default;
	~RenderCommand() = default;

	void Update(CommonUtilities::Vector2f& aPos, Tga2D::CSprite* aSprite);
	void Render();

private:
	CommonUtilities::Vector2f myPosition;
	Tga2D::CSprite* mySprite;

};

