#include <core/Core.h>
#include <core/Canvas.h>
#include <core/Color.h>
#include <core/Vector2.h>

int main(int argc, char* argv[])
{
	using namespace xy;
	Core::initialize(800, 600, L"XY Framework");

	while (Core::update())
	{
		Canvas::drawRectangle(200, 200, 50, 50, Color::magenta);
		Core::finalizeRendering();
	}

	Core::finalize();
}
