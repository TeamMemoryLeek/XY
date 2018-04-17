#pragma once
#include <string>

#include <Windows.h>

namespace xy
{

class Window
{
public:
	Window(uint32_t width, uint32_t height, const std::wstring& title);
	~Window();

private:
	HWND m_hwnd;
};

}
