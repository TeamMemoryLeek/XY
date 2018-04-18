#pragma once

#include <string>
#include <stdint.h>

namespace xy
{

class Core
{
public:
	// Creates window and does all setup needed
	static void initialize(
		uint32_t width, 
		uint32_t height, 
		const std::wstring& title);
	
	// Closes down window and xy
	static void finalize();

	static bool update();

	static void finalizeRendering();
};

}