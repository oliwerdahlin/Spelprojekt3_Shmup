#pragma once

namespace Studio
{
	class UIElement
	{
	public:
		UIElement();
		~UIElement() = default;

		virtual bool IsClicked();
		virtual void Render();

	protected:
	};
}

