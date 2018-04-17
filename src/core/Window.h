#pragma once
#include <string>

namespace xy
{

class Window
{
public:
	Window(uint32_t width, uint32_t height, const std::string& title);
	~Window();
};

}
