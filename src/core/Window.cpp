#include "Window.h"

namespace xy
{

HWND Window::_hwnd;
HDC Window::_hdc;
uint32_t Window::_width;
uint32_t Window::_height;

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
	_width = width;
	_height = height;

	static ATOM     window_class = registerClass();
	static uint32_t window_uid = 0;
	std::wstring    window_name = L"XYWindow" + std::to_wstring(window_uid++);

	_hwnd = CreateWindowExW(
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

	_hdc = GetDC(_hwnd);

	ShowWindow(_hwnd, SW_SHOW);
}

void Window::finalize()
{
	DestroyWindow(_hwnd);
}

void Window::drawToWindow(HBITMAP& map)
{
	HDC src = CreateCompatibleDC(_hdc);
	SelectObject(src, map);
	BitBlt(
		_hdc,
		0,
		0,
		_width,
		_height,
		src,
		0,
		0,
		SRCCOPY);

	DeleteDC(src);
}

void Window::pollEvents()
{
	MSG msg = {};

	while (PeekMessageA(&msg, HWND_DESKTOP, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	while(PeekMessageA(&msg, _hwnd, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

}

