#pragma once

#include <Windows.h>

class MouseManager;

class RawInputManager
{
public:

    explicit RawInputManager(MouseManager& mouseManager);

    bool Register(HWND hWnd);

    void Process(HRAWINPUT hRawInput);

private:

    MouseManager& m_mouseManager;
};