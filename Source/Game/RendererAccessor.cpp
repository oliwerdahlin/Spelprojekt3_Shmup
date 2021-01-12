#include "stdafx.h"
#include "RendererAccessor.h"

class Renderer;

namespace Studio
{
	namespace RendererAccessor
	{
		namespace
		{
			Renderer* myRendererPointer;
		}
		Renderer* GetInstance()
		{
			return myRendererPointer;
		}
		void SetInstance(Renderer* aRendererPointer)
		{
			myRendererPointer = aRendererPointer;
		}
	};
}
