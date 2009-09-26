//
// This is a skeleton Win32 application
// Ted Burke - 26-9-2009
//
// The structure of this program is quite generic and very similar to
// countless examples available on the internet in Win32 tutorials etc.
// I learned the basics of Win32 programming from theForger's Win32 API
// tutorial, which can be found at http://www.winprog.org/tutorial/
// I recommended it highly. I compiled this program with MinGW using
// the command 'gcc -o win32skeleton.exe main.c'
//

// Standard Windows header file for all Win32 programs
#include <windows.h>

// This function is the application's message handler.
// This gets called to handle any messages that Windows
// delivers to the application - e.g. mouse clicks, key
// strokes, other events.
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Process the message
	switch(msg)
	{
	case WM_PAINT:
		// Draw stuff here
		break;
	case WM_KEYDOWN:
		// Respond to a key stroke here
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	
	return 0;
}

// This function is the entry point for the program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hWnd;
	MSG msg;

	// Register window class
	wc.cbSize        = sizeof(WNDCLASSEX);
	wc.style         = 0;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = "myWindowClass";
	wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&wc);

	// Create window
	hWnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		"myWindowClass",
		"My Window Title",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		300, 200,
		NULL, NULL,
		hInstance, NULL);

	// Show window
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Main message Loop
	while(GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
