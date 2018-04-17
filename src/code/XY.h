#pragma once

#include "Window.h"

#include <string>

namespace xy
{

Window* createWindow(
	unsigned int width, 
	unsigned int height, 
	std::string& title);

void destroyWindow(Window* window);


}