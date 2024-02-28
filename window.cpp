#include "window.hpp"
#include "keyHandler.hpp"
#include "editText.hpp"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{

    LPCSTR class_name = "Text Editor Class";

    LPCSTR WindowName = "Text Editor";

    WNDCLASS wc = { };

    wc.lpfnWndProc = MainWndProc;
    wc.lpszClassName = class_name;
    wc.hInstance = hInst;

    RegisterClass(&wc);

    HWND hWnd = CreateWindowExA(
        0,
        class_name,
        WindowName,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,
        NULL,
        hInst,
        NULL
    );
    if(hWnd == 0)
    {
        return 0;
    }

    ShowWindow(hWnd, nCmdShow);

    MSG msg = { };
    while(GetMessage(&msg, NULL,0 ,0 ))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}


LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_CREATE:
            {
                drawBackground(hwnd);
            }
        case WM_SIZE:
            {
                drawBackground(hwnd);
                updateText(hwnd);
            }
            break;
        case WM_KEYDOWN:
            {
                keyHandler(hwnd, wParam);
                break;
            }
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}