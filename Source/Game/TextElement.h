#pragma once
#include "GUIElement.h"
//#include <tga2d/text/text.h>

class TextElement : public GUIElement
{
public:
	TextElement();
	~TextElement();

	void OnClick() override;
	//void SetPosition(Tga2D::Vector2f aPostion) override;
	void Update() override;
	void Render();

private:
	//Tga2D::CText myText;
};

