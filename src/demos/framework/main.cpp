#include <core/XY.h>

int main(int argc, char* argv[])
{
	xy::Core::initialize(800, 600, L"XY Framework");

	while (xy::Core::shouldRun())
	{

		xy::Core::finalizeRendering();
	}

	xy::Core::finalize();
}
