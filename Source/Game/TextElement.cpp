#include "stdafx.h"
#include "TextElement.h"

TextElement::TextElement()
{
	//myText = Tga2D::CText("Text/arial.ttf", Tga2D::EFontSize_24);
	//myText.SetText("Test");
	//myText.SetPosition({ 0.1f,0.1f });
}

TextElement::~TextElement()
{

}

void TextElement::OnClick()
{
	for (auto&& fn : mySubscribedFuntions)
	{
		fn();
	}
}

//void TextElement::SetPosition(Tga2D::Vector2f& aPostion)
//{
//	myText.SetPosition(aPostion);
//}

void TextElement::Update()
{
	//if (Studio::InputManager::GetInstance()->GetMousePosition().GetNormalized().myX > (myText.GetPosition().myX - myText.GetWidth() / 2))
	//{
	//	if (Studio::InputManager::GetInstance()->GetMousePosition().GetNormalized().myX < (myText.GetPosition().myX + myText.GetWidth() / 2))
	//	{
			if (Studio::InputManager::GetInstance()->GetMouseLPressed() == true)
			{
				OnClick();
			}
		//}
	//}
}

void TextElement::Render()
{
	//myText.Render();
}
