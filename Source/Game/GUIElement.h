#pragma once
#include <vector>
#include <functional>


class GUIElement
{
public:
	virtual void OnClick();
	//virtual void SetPosition(Tga2D::Vector2f aPosition);
	virtual void Update();
	//virtual Tga2D::Vector2f GetPostion();

	void Subscribe(std::function<void()> aFn)
	{
		mySubscribedFuntions.push_back(aFn);
	}

protected:
	std::vector<std::function<void()>> mySubscribedFuntions;

};

