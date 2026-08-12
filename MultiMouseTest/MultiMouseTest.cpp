#include <iostream>
#include <Windows.h>

#include "HiddenWindow.h"
#include "RawInputManager.h"
#include "MouseManager.h"

int main()
{
    std::cout << "MultiMouse Test\n";

    MouseManager mouseManager;

    RawInputManager rawInputManager(mouseManager);

    HiddenWindow hiddenWindow(rawInputManager);

    if (!hiddenWindow.Create())
    {
        std::cout << "Hidden Window Create or Raw Input Register Failed\n";
        return -1;
    }

    std::cout << "Hidden Window Created!\n";
    std::cout << "Move your mouse...\n";
    std::cout << "Press Ctrl+C to exit.\n";

    MSG msg{};

    while (GetMessageW(&msg, nullptr, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}