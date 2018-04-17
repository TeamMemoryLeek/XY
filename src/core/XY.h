#pragma once

#include "Window.h"

#include <string>
#include <stdint.h>

namespace xy
{

// Creates window and sets up canvas
Window* createWindow(
	uint32_t width, 
	uint32_t height,
	const std::wstring& title);

// Destroys window and canvas
void destroyWindow(Window* window);

// Checks if user has pressed the exit button
bool shouldRun();

// Call this at the start of your rendering loop
void clearScreen();

// Call this function at the end of your rendering loop
void finalizeRendering();

}