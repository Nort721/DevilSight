#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

void ShowControlPanel(HINSTANCE hInstance)
{
    // Define window class
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WindowProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "MyWindowClass", NULL };
    RegisterClassEx(&wc);

    // Create window
    HWND hwnd = CreateWindow(wc.lpszClassName, "My Window", WS_OVERLAPPEDWINDOW, 100, 100, 443, 265, NULL, NULL, wc.hInstance, NULL);

    // Set window background color
    HBRUSH bgColor = CreateSolidBrush(RGB(32, 33, 36));
    SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG_PTR)bgColor);

    // Create buttons
    HWND button1 = CreateWindow("BUTTON", "Button 1", WS_CHILD | WS_VISIBLE, 95, 153, 239, 23, hwnd, (HMENU)1, wc.hInstance, NULL);
    HWND button2 = CreateWindow("BUTTON", "Button 2", WS_CHILD | WS_VISIBLE, 95, 183, 239, 23, hwnd, (HMENU)2, wc.hInstance, NULL);

    // Show the window
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);

    // Main message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Cleanup
    DeleteObject(bgColor);
    UnregisterClass(wc.lpszClassName, wc.hInstance);
}
