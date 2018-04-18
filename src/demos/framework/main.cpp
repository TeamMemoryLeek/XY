#include <core/Core.h>
#include <core/Canvas.h>
#include <core/Color.h>
#include <core/Vector2.h>

int main(int argc, char* argv[])
{
	using namespace xy;

	const int WIDTH = 800;
	const int HEIGHT = 600;
	Core::initialize(WIDTH, HEIGHT, L"XY Framework");

	while (Core::update())
	{
		Canvas::clear(Color(200, 240, 255));
		Canvas::drawRectangle(200, 200, 50, 50, Color::magenta);
		Core::finalizeRendering();
	}

	Core::finalize();
}
