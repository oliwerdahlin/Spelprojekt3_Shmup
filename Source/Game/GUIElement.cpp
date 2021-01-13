#include "stdafx.h"
#include "GUIElement.h"

void GUIElement::OnClick()
{
    for (auto&& fn : mySubscribedFuntions)
    {
        fn();
    }
}
