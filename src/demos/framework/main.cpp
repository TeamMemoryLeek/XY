#include <core/Core.h>
#include <core/Canvas.h>
#include <core/Color.h>
#include <core/Vector2.h>

int main(int argc, char* argv[])
{
	using namespace xy;

	const int WIDTH = 800;
	const int HEIGHT = 600;
	Core::initialize(WIDTH, HEIGHT, L"XY Framework", WIDTH / 16, HEIGHT / 16);

	while (Core::update())
	{
		Canvas::clear(Color(255, 0, 255));
		Canvas::drawPixel(16, 16, Color::black);
		Core::finalizeRendering();
	}

	Core::finalize();
}
