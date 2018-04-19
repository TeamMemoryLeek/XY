#include "Core.h"
#include "Window.h"
#include "Canvas.h"
#include "Keyboard.h"
#include "Time.h"

namespace xy
{

void Core::initialize(
	uint32_t width, 
	uint32_t height, 
	const std::wstring& title,
	uint32_t canvasWidth /*= 0*/,
	uint32_t canvasHeight /*= 0*/)
{
	Window::initialize(width, height, title);
	if (canvasWidth == 0)
		canvasWidth = width;
	if (canvasHeight == 0)
		canvasHeight = height;
	Canvas::initialize(canvasWidth, canvasHeight);
	Keyboard::initialize();
	Window::keyCallback = Keyboard::keyCallback;
	Window::resizeCallback = resizeCallback;
	Time::initialize();
}

void Core::finalize()
{
	Canvas::finalize();
	Window::finalize();
}

bool Core::update()
{
	Time::update();
	Keyboard::update();
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

	Window::drawToWindow(map, Canvas::_width, Canvas::_height);

	DeleteObject(map);
}

Image* Core::loadImage(const std::string& path)
{
	Image* image = new Image;
	image->loadFromFile(path);
	return image;
	// TODO: Cache image and destroy automatically
}

void Core::destroyImage(Image* image)
{
	delete image;
}

void Core::resizeCallback(int width, int height)
{
}

}