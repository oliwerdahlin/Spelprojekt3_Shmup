#pragma once

class Renderer;

namespace Studio
{
	namespace RendererAccessor
	{
		Renderer* GetInstance();
		void SetInstance(Renderer* aRendererPointer);
	};
}


