#pragma once
#include <vector>
#include <array>
#include "RenderCommand.h"

class Renderer
{
public:
	Renderer() = default;
	~Renderer() = default;
	void Init();
	void AddGameObjectToRenderBuffer();
	void SwapBuffers();
	void Render();

private:
	std::vector<RenderCommand>& GetReadFromBuffer() const;
	std::vector<RenderCommand>& GetWriteToBuffer();
	std::array<std::vector<RenderCommand>, 2> myRenderBuffers;
	std::vector<RenderCommand>* myWriteToBuffer;
	std::vector<RenderCommand>* myReadFromBuffer;
};

