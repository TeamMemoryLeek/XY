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
	Canvas::initialize(width, height);
}

void Core::finalize()
{
	Canvas::finalize();
	Window::finalize();
}

bool Core::update()
{
	return Window::pollEvents();
}

void Core::finalizeRendering()
{
	HBITMAP map = CreateBitmap(
		Canvas::_width, 
		Canvas::_height, 
		1, 
		8 * 4, 
		(void*)Canvas::_pixels);

	Window::drawToWindow(map);
}

}