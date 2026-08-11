#include <iostream>

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
        std::cout << "Hidden Window Create Failed\n";
        return -1;
    }

    std::cout << "Hidden Window Created!\n";

    std::cin.get();

    return 0;
}