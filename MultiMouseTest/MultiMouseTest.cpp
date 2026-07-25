#include <iostream>

#include "MouseManager.h"
#include "RawInputManager.h"
#include "HiddenWindow.h"

int main()
{
    MouseManager mouseManager;

    RawInputManager rawInputManager(mouseManager);

    HiddenWindow hiddenWindow(rawInputManager);

    if (!hiddenWindow.Create())
    {
        std::cout << "Create Failed\n";
        return -1;
    }

    std::cout << "Hidden Window Created!\n";

    std::cin.get();

    return 0;
}