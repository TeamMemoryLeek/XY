#include <core/Core.h>
#include <core/Canvas.h>
#include <core/Color.h>
#include <core/Vector2.h>
#include <core/Keyboard.h>
#include <core/Time.h>

int main(int argc, char* argv[])
{
	using namespace xy;

	const int WIDTH = 1280;
	const int HEIGHT = 720;
	Core::initialize(WIDTH, HEIGHT, L"XY Framework", WIDTH / 4, HEIGHT / 4);
	Image* image = Core::loadImage("image.bmp");

	float x = 0.0f;
	float y = 0.0f;

	while (Core::update())
	{
		Canvas::clear(Color::black);
		if (Keyboard::getKey('W')) 
			y -= Time::deltaTime;
		if (Keyboard::getKey('S'))
			y += Time::deltaTime;
		if (Keyboard::getKey('A'))
			x -= Time::deltaTime;
		if (Keyboard::getKey('D'))
			x += Time::deltaTime;

		printf("%f\n", 1.0f / Time::deltaTime);

		Canvas::drawImage((int)(x * 32.0f), (int)(y * 32.0f), image);

		Core::finalizeRendering();
	}

	Core::finalize();
}
