#pragma once

#include <string>
#include <stdint.h>

namespace xy
{

class Core
{
public:
	static void initialize(
		uint32_t width, 
		uint32_t height, 
		const std::wstring& title);
	
	static void finalize();

	static bool shouldRun();

	static void update();

	static void finalizeRendering();
};

}