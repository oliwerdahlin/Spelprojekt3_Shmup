#include "stdafx.h"
#include "GameObject.h"
namespace Studio
{
	void GameObject::Update(const Tga2D::Vector2f& aPos)
	{
		myRenderCommand.Update(aPos);
	}
	GameObject::GameObject(const Tga2D::Vector2f& aPos, Tga2D::CSprite* aSprite)
		: myRenderCommand(aPos, aSprite)
	{
	}
	Sprite& Studio::GameObject::GetSprite()
	{
		return mySprite;
	}

	Health& Studio::GameObject::GetHealth()
	{
		return myHealth;
	}

	const Studio::RenderCommand& GameObject::GetRenderCommand() const
	{
		return myRenderCommand;
	}

	bool GameObject::Intersects(const GameObject& aGameObject)
	{
		return myCollider.Intersects(aGameObject.myCollider);
	}
	bool GameObject::Contains(const GameObject& aGameObject)
	{
		return myCollider.Contains(aGameObject.myCollider);
	}
}
