//#include <Windows.h>
//#include "WindowsMessageMap.h"
//#include <sstream>

#include "Window.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int		  nCmdShow)
{

	try
	{
		Window wnd(800, 300, "Donkey Fart Box With Noodles!!!");

		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			/******************** KEYBOARD MESSAGE TEST ********************/
			if (wnd.kbd.KeyIsPressed(VK_SPACE))
			{
				MessageBoxA(nullptr, "Something Happen!", "Spacebar Key Was Pressed!", MB_OK | MB_ICONEXCLAMATION);
			}
			/******************** END KEYBOARD MESSAGE TEST ********************/
		}

		// check if GetMessage call itself borked
		if (gResult == -1)
		{
			throw CHWND_LAST_EXCEPT();
		}
		// wParam here is the value passed to PostQuitMessage
		return msg.wParam;
	}
	catch (const ChiliException& e)
	{
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBoxA(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBoxA(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}