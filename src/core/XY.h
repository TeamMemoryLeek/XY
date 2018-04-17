#pragma once

#include "Window.h"

#include <string>

namespace xy
{

// Creates window and sets up canvas
Window* createWindow(
	unsigned int width, 
	unsigned int height, 
	std::string& title);

// Destroys window and canvas
void destroyWindow(Window* window);

// Checks if user has pressed the exit button
bool shouldRun();

// Call this function at the end of your rendering loop
void finalizeRendering();

}