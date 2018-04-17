#include "Window.h"

namespace xy
{

LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	default:
		return DefWindowProcW(hwnd, msg, wparam, lparam);
	}
}

static ATOM registerClass()
{
	WNDCLASSEXW desc = {};
	desc.cbSize        = sizeof(WNDCLASSEXW);
	desc.style         = CS_HREDRAW | CS_VREDRAW;
	desc.lpfnWndProc   = wndProc;
	desc.hInstance     = GetModuleHandle(nullptr);
	desc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	desc.lpszClassName = L"XYWindowClass";

	return RegisterClassExW(&desc);
}

void Window::initialize(uint32_t width, uint32_t height, const std::wstring& title)
{
	static ATOM     window_class = registerClass();
	static uint32_t window_uid = 0;
	std::wstring    window_name = L"XYWindow" + std::to_wstring(window_uid++);

	m_hwnd = CreateWindowExW(
		WS_EX_OVERLAPPEDWINDOW,
		L"XYWindowClass",
		window_name.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		(int)width, (int)height,
		nullptr, nullptr,
		GetModuleHandle(nullptr),
		nullptr
	);

	ShowWindow(m_hwnd, SW_SHOW);
}

void Window::finalize()
{
	DestroyWindow(m_hwnd);
}

}

