#include "XY.h"
#include "Canvas.h"

namespace xy
{

static Window* window = nullptr;
static Canvas* canvas = nullptr;

Window* createWindow(
	unsigned int width, 
	unsigned int height,
	std::string& title)
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

}