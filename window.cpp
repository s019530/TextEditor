#include "window.hpp"

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
        std::cout << std::to_string(GetLastError());
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
        case WM_SIZE:
            {
                int width = LOWORD(lParam);
                int height = HIWORD(lParam);
                OnResize(hwnd, (UINT) wParam, width, height);
            }
            break;
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

void OnResize(HWND hwnd, UINT flag, int width, int height)
{
    PAINTSTRUCT paints;
    HDC hdc = BeginPaint(hwnd, &paints);

    RECT rect;
    GetClientRect(hwnd, &rect);

    //FillRect(hdc, &paints.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
    DrawText(hdc, "hello", 5, &rect, DT_CENTER);
    EndPaint(hwnd, &paints);

}