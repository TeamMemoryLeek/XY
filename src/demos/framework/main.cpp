#include <audio/SoundItf.h>
#include <audio/XAudio2/XAudio2Device.h>
#include <core/Core.h>
#include <core/Canvas.h>
#include <core/Color.h>
#include <core/Vector2.h>
#include <core/Keyboard.h>
#include <core/Time.h>
#include <core/Window.h>

static const wchar_t* TITLE = L"XY Framework  |  ";
static const int WIDTH = 1280;
static const int HEIGHT = 720;

void handleTitle()
{
	using namespace xy;
	static double timer = 0.0f;
	timer += Time::deltaTime;
	if (timer >= 1.0)
	{
		timer -= 1.0;
		Window::setTitle(TITLE + std::to_wstring(1.0f / Time::deltaTime));
	}
}

int main(int argc, char* argv[])
{
	using namespace xy;
	Core::initialize(WIDTH, HEIGHT, TITLE, WIDTH / 4, HEIGHT / 4);
	Image* image = Core::loadImage("image2.bmp");

	XAudio2Device audioDevice;
	SoundItf* crankSound = audioDevice.loadSound("crank.wav");

	crankSound->play();

	double x = 0.0;
	double y = 0.0;

	while (Core::update())
	{
		handleTitle();
		Canvas::clear(Color::black);
		if (Keyboard::getKey('W')) 
			y -= Time::deltaTime * 32.0;
		if (Keyboard::getKey('S'))
			y += Time::deltaTime * 32.0;
		if (Keyboard::getKey('A'))
			x -= Time::deltaTime * 32.0;
		if (Keyboard::getKey('D'))
			x += Time::deltaTime * 32.0;

		Canvas::drawImagePortion((int)x, (int)y, 8, 8, 8, 8, image);

		Core::finalizeRendering();
	}

	Core::finalize();
}
