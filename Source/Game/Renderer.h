#pragma once
#include <vector>
#include <array>
#include "GameObject.h"

namespace Studio
{
	class GameObject;
}

class Renderer
{
public:
	Renderer()
	{
		myReadFromBuffer = nullptr;
		myWriteToBuffer = nullptr;
	}
	~Renderer() = default;
	void Init();
	void RenderRenderCommand(Studio::RenderCommand aRenderCommand);
	void Render(Studio::GameObject& aGameObject);
	void SwapBuffers();
	void Render();

private:
	std::vector<Studio::RenderCommand>& GetReadFromBuffer() const;
	std::vector<Studio::RenderCommand>& GetWriteToBuffer();
	std::array<std::vector<Studio::RenderCommand>, 2> myRenderBuffers;
	std::vector<Studio::RenderCommand>* myWriteToBuffer;
	std::vector<Studio::RenderCommand>* myReadFromBuffer;
};

