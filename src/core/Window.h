#pragma once
#include <string>

#include <Windows.h>

namespace xy
{

class Window
{
public:
	static void setTitle(const std::wstring& title);
private:
	static ATOM registerClass();
	static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	static void initialize(uint32_t width, uint32_t height, const std::wstring& title);
	static void finalize();

	static bool pollEvents();
	static void drawToWindow(HBITMAP& map, uint32_t width, uint32_t height);

	static HWND _hwnd;
	static HDC _hdc;

	static uint32_t _width;
	static uint32_t _height;

	static void(*keyCallback)(int action, int key);
	static void(*resizeCallback)(int width, int height);

	friend class Core;
};

}
