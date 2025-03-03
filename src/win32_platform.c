#include "utils.c"

#include <windows.h>

struct {
    int width, height;
    u32 *pixels;
    BITMAPINFO bitmap_info;
} typedef Render_Buffer;

Render_Buffer render_buffer;

internal LRESULT CALLBACK window_callback(HWND window, UINT message,
                        WPARAM w_param, LPARAM l_param)
{
    LRESULT result = 0;

    switch (message) {
        case WM_CLOSE:
        case WM_DESTROY:
            running = false;
            break;
        default:
            result = DefWindowProcA(window, message, w_param, l_param);
    }

    return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
            LPSTR lpCmdLine, int nShowCmd)
{
    WNDCLASSA window_class = {0};
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc = window_callback; 
    window_class.lpszClassName = "Game_Window_Class";

    RegisterClassA(&window_class);

    HWND window = CreateWindowExA(0, window_class.lpszClassName, "Breakout",
                                    WS_VISIBLE | WS_OVERLAPPEDWINDOW,
                                    CW_USEDEFAULT, CW_USEDEFAULT,
                                    1280, 720,
                                    0, 0, 0, 0);

    HDC hdc = GetDC(window);
    
    while (running) {
        // Input
        MSG message;
        while (PeekMessageA(&message, window, 0, 0, PM_REMOVE)) {
            // For every message, do X
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        // Simulation
        int width, height;
        void *memory;
        BITMAPINFO bitmap_info;

        // Render
        StretchDIBits(hdc,
                        0, 0, render_buffer.width, render_buffer.height,
                        0, 0, render_buffer.width, render_buffer.height,
                        render_buffer.pixels, &render_buffer.bitmap_info,
                        DIB_RGB_COLORS, SRCCOPY);
    }
}
