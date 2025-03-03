#include <windows.h>

LRESULT CALLBACK window_callback(HWND window, UINT message,
                        WPARAM w_param, LPARAM l_param)
{
    return DefWindowProcA(window, message, w_param, l_param);
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
}
