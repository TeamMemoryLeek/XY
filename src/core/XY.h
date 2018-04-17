#pragma once

#include <string>
#include <stdint.h>

namespace xy
{

struct Core
{
	static void initialize(
		uint32_t width, 
		uint32_t height, 
		const std::wstring& title);
	static void finalize();

	static bool shouldRun();

	static void finalizeRendering();
};

}