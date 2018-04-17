#include "Core.h"
#include "Window.h"
#include "Canvas.h"

namespace xy
{

void Core::initialize(
	uint32_t width, 
	uint32_t height, 
	const std::wstring& title)
{
	Window::initialize(width, height, title);
}

void Core::finalize()
{
	Window::finalize();
}

bool Core::shouldRun()
{
	return false;
}

void Core::finalizeRendering()
{
}

}