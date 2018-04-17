#pragma once
#include <string>

#include <Windows.h>

namespace xy
{

class Window
{
public:
	static void initialize(uint32_t width, uint32_t height, const std::wstring& title);
	static void finalize();
private:
	static HWND m_hwnd;
};

}
