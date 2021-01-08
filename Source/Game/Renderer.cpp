#include "stdafx.h"
#include "Renderer.h"

void Renderer::Init()
{
	myReadFromBuffer = &myRenderBuffers[1];
	myWriteToBuffer = &myRenderBuffers[0];
}
/// <summary>
/// Add a game object to the render buffer
/// </summary>
void Renderer::AddGameObjectToRenderBuffer()
{
	//PushBack till GetWriteToBuffer() så det kan renderas
}

void Renderer::SwapBuffers()
{
	std::vector<RenderCommand>* temp_buffer_pointer = &(*myWriteToBuffer);
	myWriteToBuffer = &(*myReadFromBuffer);
	myReadFromBuffer = &(*temp_buffer_pointer);
	myWriteToBuffer->clear();
}

void Renderer::Render()
{
	//Render the CSprite on the render commands
	for (int i = static_cast<int>(myReadFromBuffer->size()); i-- > 0;)
	{
		//GetReadFromBuffer()[i].Render();
	}
}

std::vector<RenderCommand>& Renderer::GetReadFromBuffer() const
{
	return (*myReadFromBuffer);
}

std::vector<RenderCommand>& Renderer::GetWriteToBuffer()
{
	return (*myWriteToBuffer);
}
