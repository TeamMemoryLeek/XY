#include <core/XY.h>

int main(int argc, char* argv[])
{
	xy::Window* window = xy::createWindow(800, 600, L"XY Framework");

	while (xy::shouldRun())
	{
		xy::clearScreen();

		xy::finalizeRendering();
	}

	xy::destroyWindow(window);
}
