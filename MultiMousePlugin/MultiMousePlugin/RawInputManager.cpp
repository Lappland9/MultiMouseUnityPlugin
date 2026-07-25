#include "RawInputManager.h"
#include "MouseManager.h"
#include <Windows.h>

RawInputManager::RawInputManager(MouseManager& mouseManager)
    : m_mouseManager(mouseManager)
{
}

bool RawInputManager::Register(HWND hWnd)
{
    RAWINPUTDEVICE device{};

    // Generic Desktop Controls
    device.usUsagePage = 0x01;

    // Mouse
    device.usUsage = 0x02;

    // バックグラウンドでも受信する
    device.dwFlags = RIDEV_INPUTSINK;

    // 送り先
    device.hwndTarget = hWnd;

    if (!RegisterRawInputDevices(
        &device,
        1,
        sizeof(RAWINPUTDEVICE)))
    {
        return false;
    }

    return true;
}

void RawInputManager::Process(HRAWINPUT hRawInput)
{
}