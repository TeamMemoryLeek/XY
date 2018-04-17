#include "Window.h"

#include <Windows.h>

namespace xy
{

Window::Window(uint32_t width, uint32_t height, const std::wstring& title)
{
	static uint32_t window_uid = 0;
	std::wstring window_name = L"XYWindow" + std::to_wstring(window_uid++);

	m_hwnd = CreateWindowExW(
		WS_EX_OVERLAPPEDWINDOW,
		L"XYWindowClass",
		window_name.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		(int)width, (int)height,
		nullptr, nullptr,
		GetModuleHandleW(nullptr),
		nullptr
	);

	ShowWindow(m_hwnd, SW_SHOW);
}

Window::~Window()
{
	DestroyWindow(m_hwnd);
}

}

