#pragma once
#include <string>

#include <Windows.h>

namespace xy
{

class Window
{
private:
	static void initialize(uint32_t width, uint32_t height, const std::wstring& title);
	static void finalize();

	static void pollEvents();
	static void drawToWindow(HBITMAP& map);

	static HWND _hwnd;
	static HDC _hdc;

	static uint32_t _width;
	static uint32_t _height;

	friend class Core;
};

}
