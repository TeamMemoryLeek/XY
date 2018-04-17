#include "XY.h"
#include "Canvas.h"

namespace xy
{

static Window* window = nullptr;
static Canvas* canvas = nullptr;

Window* createWindow(
	uint32_t width, 
	uint32_t height,
	const std::wstring& title)
{
	canvas = new Canvas(width, height);
	window = new Window(width, height, title);
	return window;
}

void destroyWindow(Window* window)
{
	delete window;
	delete canvas;
}

bool shouldRun()
{
	// TODO: Check if user has pressed exit
	return false;
}

void clearScreen()
{
	// TODO: Clear screen
}

void finalizeRendering()
{
	// TODO: Blit canvas to backbuffer
}

}