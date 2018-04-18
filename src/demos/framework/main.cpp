#include <core/Core.h>
#include <core/Canvas.h>
#include <core/Color.h>

int main(int argc, char* argv[])
{
	xy::Core::initialize(800, 600, L"XY Framework");

	while (xy::Core::shouldRun())
	{
		xy::Core::update();
		xy::Canvas::drawRectangle(0, 0, 800, 600, xy::Color::blue);
		xy::Core::finalizeRendering();
	}

	xy::Core::finalize();
}
