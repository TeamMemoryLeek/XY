#include <core/Core.h>
#include <core/Canvas.h>
#include <core/Color.h>
#include <core/Vector2.h>
#include <core/Keyboard.h>

int main(int argc, char* argv[])
{
	using namespace xy;

	const int WIDTH = 800;
	const int HEIGHT = 600;
	Core::initialize(WIDTH, HEIGHT, L"XY Framework", WIDTH, HEIGHT);

	float x = 0.0f;
	float y = 0.0f;

	while (Core::update())
	{
		Canvas::clear(Color(255, 0, 255));
		if (Keyboard::getKeyDown('W')) 
			y--;
		if (Keyboard::getKeyDown('S'))
			y++;
		if (Keyboard::getKeyDown('A'))
			x--;
		if (Keyboard::getKeyDown('D'))
			x++;

		Canvas::drawRectangle((int)x * 100, (int)y * 100, 100, 100, Color::black);
		Core::finalizeRendering();
	}

	Core::finalize();
}
