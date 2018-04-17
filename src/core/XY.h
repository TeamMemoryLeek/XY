#pragma once

#include "Window.h"

#include <string>

namespace xy
{

// Creates window and sets up canvas
Window* createWindow(
	unsigned int width, 
	unsigned int height, 
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