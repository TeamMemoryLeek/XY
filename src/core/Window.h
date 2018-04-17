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
	static HWND _hwnd;

	friend class Core;
};

}
