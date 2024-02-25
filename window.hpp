#include <iostream>
#include <windows.h>
#include <winuser.h>


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow);

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void OnResize(HWND hwnd, UINT flag, int width, int height);